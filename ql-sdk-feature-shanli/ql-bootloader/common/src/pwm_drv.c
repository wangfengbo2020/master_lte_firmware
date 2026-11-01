#include "plat_types.h"
//#include "plat_basic_api.h"
//#include "ui_log_api.h"

#include "__regs_pwm.h"

//#include "clock_api.h"

struct pwm_ctl {
	unsigned int pwm_cr; /*address*/
	unsigned int pwm_dcr;
	unsigned int pwm_pcr;

	unsigned long clk_freq;
};

static struct pwm_ctl pwm[4];

/**
How to get the PV(The value of after scaled clock cycles per cycle/T):
InputClockT * ('PV(The value of before scaled clock cycles per cycle)) = PWM_T
	'PV   = PWM_T / InputClockT
		 = PWM_T * InputClockF
	PV = 'PV /(prescale + 1) -1

How to get the prescale:
	Because the internal clock period counter is 10-bit, to avoid overun. We can use the prescale.
	prescale real value  = ('PV - 1(if > 1024, then need prescale)) / 1024

How to get the Duty cycle:
	Duty cycle = (PV(the cycles per T) + 1) * ratio(Duty time/PWM_T)

*/
static int __pwm_set_para(struct pwm_ctl *p, int period_ns, int duty_ns)
{
	unsigned long period_cycles, prescale, pv, dc;
	unsigned long long clk_freq;

	clk_freq = p->clk_freq;
	clk_freq = clk_freq * period_ns;
	clk_freq = clk_freq / (1*1000*1000*1000);

	period_cycles = clk_freq;

	if (period_cycles < 1)
		period_cycles = 1;

	prescale = (period_cycles - 1) / 1024;

	pv = period_cycles / (prescale + 1) - 1;

	if (prescale > 63) {
		raw_uart_log("clock and period are too large, Both prescale is overun!\n\r");
		return -1;
	}
	if (duty_ns == period_ns)
		dc = BIT_FD;
	else
		dc = (pv + 1) * duty_ns / period_ns;

	/* NOTE: the clock to PWM has to be enabled first
	 * before writing to the registers
	 */
	//__pwm_enable(p);
	
	raw_uart_log("prescale = 0x%x, dc = 0x%x, pv = 0x%x\n\r", prescale, dc, pv);
	CHIP_REG_OR(p->pwm_cr, prescale);
	write32(p->pwm_dcr, dc);
	write32(p->pwm_pcr, pv);

	return 0;
}


static void pwm_shutdow_mode(struct pwm_ctl *p, int is_graceful_down)
{
	//unsigned int addr;
	if (is_graceful_down) {
		CHIP_REG_AND(p->pwm_cr,  ~BIT_SD);
	} else {
		CHIP_REG_OR(p->pwm_cr,  BIT_SD);
	}
}

/*Only support port 0, 1, 2, 3*/
int pwm_start_work(int port, int period_ns, int duty_ns)
{
	if (port > 3)
		return -1;
	return __pwm_set_para(&pwm[port], period_ns, duty_ns);
}

/*Only support port 0, 1, 2, 3*/
int pwm_set_shutdown_mode(int port, int is_graceful_down)
{
	if (port > 3)
		return -1;

	pwm_shutdow_mode(&pwm[port], is_graceful_down);
	return 0;
}

/*Only support port 0, 1, 2, 3*/
int pwm_disable(int port)
{
	if (port > 3)
		return -1;

	write32((APBC_PWM0_CLK_RST + port * 4), 0);
	return 0;
}

/*Only support port 0, 1, 2, 3*/
int pwm_enable(int port,unsigned long clk_freq)
{
	if (port > 3)
		return -1;
	if(clk_freq == 12800000)
		write32((APBC_PWM0_CLK_RST + port * 4),0x3 | (PWM_13M <<4));
	else
		write32((APBC_PWM0_CLK_RST + port * 4),0x3 | (PWM_32K <<4));
	return 0;
}


void pwm_module_init(int port, unsigned long clk_freq)
{
	//unsigned long long clk_freq;

	if (port >= ARR_SIZE(pwm)) {
		raw_uart_log("pwm_module_init wrong: port = %d\n\r",port);
		return;
	}

	//clk_freq = pwm_clksource_select(clk_id);
	raw_uart_log("pwm clock frequency  is %d\n",clk_freq);

	pwm[port].pwm_cr = REG_PWM0_PWM_CRx + port * 0x400;
	pwm[port].pwm_dcr= REG_PWM0_PWM_DCR + port * 0x400;
	pwm[port].pwm_pcr= REG_PWM0_PWM_PCR + port * 0x400;
	pwm[port].clk_freq = clk_freq;
	pwm_enable(port,clk_freq);
}
