#ifndef __PSRAM_H
#define __PSRAM_H
#include "cpu.h"

#define PSRAM_BASE  (0xc0100000)


#define GEU_BASE                                    0xD4201000
#define GEU_BLOCK3_RESERVED_191_160                 (GEU_BASE + 0x04A4)
#define PSRAM_REG32(x)	(*((volatile uint32_t *)(x)))

#define PMU_MAIN                                    0xD4050000
#define ACGR                                        (PMU_MAIN + 0x1024) /* Marvell Seagull/Mohawk Clock Gating Register */
#define APMU_104M_BIT                               12 /* bit12 */

/* PMU AP */
#define PMU_AES_CLK_RES_CTRL                        (PMU_BASE + 0x68) /* AES Clock/Reset Control Register */


/* PMU_AES_CLK_RES_CTRL */
typedef union {
  struct {
    unsigned aes_axi_reset                  : 1;        /* bit 0 */
    unsigned reserved0                      : 2;        /* bit 2:1 */
    unsigned aes_axi_clk_en                 : 1;        /* bit 3 */
    unsigned reserved1                      : 28;       /* bit 31:4 */
  } s;
  unsigned value;
} pmu_aes_clk_res_ctrl_t;

void psram_set(void);

#endif
