;==================================================================
; Copyright ARM Ltd 2006-2014. All rights reserved.
;
; Cortex-R5(F) Embedded example - Startup Code
;==================================================================

; MPU region defines

Region_32B     EQU 2_00100
Region_64B     EQU 2_00101
Region_128B    EQU 2_00110
Region_256B    EQU 2_00111
Region_512B    EQU 2_01000
Region_1K      EQU 2_01001
Region_2K      EQU 2_01010
Region_4K      EQU 2_01011
Region_8K      EQU 2_01100
Region_16K     EQU 2_01101
Region_32K     EQU 2_01110
Region_64K     EQU 2_01111
Region_128K    EQU 2_10000
Region_256K    EQU 2_10001
Region_512K    EQU 2_10010
Region_1M      EQU 2_10011
Region_2M      EQU 2_10100
Region_4M      EQU 2_10101
Region_8M      EQU 2_10110
Region_16M     EQU 2_10111
Region_32M     EQU 2_11000
Region_64M     EQU 2_11001
Region_128M    EQU 2_11010
Region_256M    EQU 2_11011
Region_512M    EQU 2_11100
Region_1G      EQU 2_11101
Region_2G      EQU 2_11110
Region_4G      EQU 2_11111

Region_Enable  EQU 2_1

Execute_Never  EQU 0x1000  ; Bit 12
Normal_nShared EQU 0x03 ; Outer and Inner write-back, no write-allocate
Device_nShared EQU 0x10
Normal_nShared_nCacheable EQU 0x08 ; normal memory, non-shared, non-cacheable.
Normal_nShared_Cacheable EQU 0x03 ; normal memory, non-shared, cacheable.
Normal_Shared_nCacheable EQU 0x0C ; normal memory, shared, non-cacheable.
Full_Access    EQU 2_011
Read_Only      EQU 2_110

Mode_USR        EQU     0x10
Mode_FIQ        EQU     0x11
Mode_IRQ        EQU     0x12
Mode_SVC        EQU     0x13
Mode_ABT        EQU     0x17
Mode_UND        EQU     0x1B
Mode_SYS        EQU     0x1F

I_Bit           EQU     0x80            ; when I bit is set, IRQ is disabled
F_Bit           EQU     0x40            ; when F bit is set, FIQ is disabled

UND_Stack_Size  EQU     0x00000000
SVC_Stack_Size  EQU     0x00004000		; Supervisor Mode stack size		
ABT_Stack_Size  EQU     0x00000000
FIQ_Stack_Size  EQU     0x00000000
IRQ_Stack_Size  EQU     0x00001000		; interrupt stack size
USR_Stack_Size  EQU     0x00000000
Stack_Size      EQU     (UND_Stack_Size + SVC_Stack_Size + ABT_Stack_Size + \
                         FIQ_Stack_Size + IRQ_Stack_Size)

MODE_MASK	EQU	 0x1F		 ; Processor Mode Mask
SUP_MODE	EQU	 0x13		 ; Supervisor Mode (SVC)
IRQ_MODE	EQU	 0x12		 ; Interrupt Mode (IRQ)
FIQ_MODE	EQU	 0x11		 ; Fast Interrupt Mode (FIQ)
UND_MODE	EQU	 0x1B		 ; Undefined Mode (UND)
ABT_MODE	EQU	 0x17		 ; Abort Mode (ABT)

	IMPORT ||Load$$INIT$$Base||
                         
MAGIC_NUMBER                EQU 0xBABE5F5F
IMAGE_LOAD_ADDRESS          EQU ImageHeader				 ;||Load$$INIT$$Base||  ;;0x7E030000  ;0x7E060000
LOGO_DISPLAY_MAGIC_ADDRESS  EQU IMAGE_LOAD_ADDRESS       ;magic number to make sure logo.bin is correct in its partition.
LOGO_DISPLAY_EXEC_ADDRESS   EQU IMAGE_LOAD_ADDRESS+4     ;the entry address of logo.bin, so boot33 can call logo.bin from here. 
LOGO_DISPLAY_RET_ADDRESS    EQU IMAGE_LOAD_ADDRESS+8     ;reserved

LOGO_CONTEXT_SIZE           EQU 256			             ;the context data of boot33 before calling logo.bin

				PRESERVE8

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
StartAddress
Stack_Mem       SPACE   Stack_Size
Stack_Top
                AREA  ImageHeader, CODE,READONLY
   ;Need to make sure below setting are correct data and placed in designed address after generating logo.bin.
_logoContextRegs 	SPACE LOGO_CONTEXT_SIZE     ;space to store context registers from boot33
_logoContextRegsEnd
_pContextRegs
				    DCD _logoContextRegs ;; cpuRegs is the first field.

              ;;  ENTRY
                EXPORT  Reset_Handler

;-------------------------------------------------------	
    MACRO
$saveCtext SAVECONTEXT 
	;; load the backup struct's address
	LDR R0, _pContextRegs       ; (R0 is intput, it contains the parameter we don't need so we can use it)
	
	;; Backup usr CPU registers. (r1-r14)
	STMIA R0, {R1-R14}^       ; Store the registers and increment the pointer.
	ADD   R0,R0,#0x38					; increment the pointer (4*14 registers)
	                      ; (no real need to backup R0)
	;; Backup the CPSR
	MRS   R1, CPSR	           ; Pickup current CPSR.
	STMIA R0!, {R1}            ; Store the register and increment the pointer.

	;; Change mode to FIQ
	;MRS     R1,CPSR           ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#FIQ_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Backup fiq CPU registers.
	STMIA R0!, {R8-R14}        ; Store the registers and increment the pointer.

	;; Change mode to ABT
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#ABT_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Backup abt CPU registers.
	STMIA R0!, {R13,R14}       ; Store the registers and increment the pointer.

	;; Change mode to UND
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#UND_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Backup und CPU registers. 
	STMIA R0!, {R13,R14}       ; Store the registers and increment the pointer.

	;; Change mode to IRQ
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#IRQ_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Backup irq CPU registers.
	STMIA R0!, {R13,R14}       ; Store the registers and increment the pointer.


	;; Change mode to SVC
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#SUP_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Backup svc CPU registers.
	STMIA R0!, {R13,R14}       ; Store the registers and increment the pointer.

	;BX LR
	MEND


   ;----------------------------------------
	MACRO
$restoreCtext RESTORECONTEXT
	LDR R0, _pContextRegs       ; load the backup struct's address
	                       
	;; No use in restoring the CPSR and usr registers now.
	ADD R0, R0, #0x3C          ; increment R0 by 15*UINT32 (the size of all registers)                               


	;; Change mode to FIQ
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#FIQ_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Restore fiq CPU registers.
	LDMIA R0!, {R8-R14}       ; Restore the registers and increment the pointer.


	;; Change mode to ABT
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#ABT_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Restore abt CPU registers.
	LDMIA R0!, {R13,R14}       ; Restore the registers and increment the pointer.


	;; Change mode to UND
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#UND_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Restore und CPU registers. 
	LDMIA R0!, {R13,R14}       ; Restore the registers and increment the pointer.


	;; Change mode to IRQ
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#IRQ_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Restore irq CPU registers.
	LDMIA R0!, {R13,R14}       ; Restore the registers and increment the pointer.

	;; Change mode to SVC
	MRS     R1,CPSR            ; Pickup current CPSR
	BIC     R1,R1,#MODE_MASK   ; Clear the mode bits
	ORR     R1,R1,#SUP_MODE    ; Set the new mode bits to the CPSR image
	MSR     CPSR_cxsf,R1       ; Setup the new CPSR

	;; Restore svc CPU registers.
	LDMIA R0!, {R13,R14}       ; Restore the registers and increment the pointer.


	;; Restore usr CPU registers.
	LDR R0, _pContextRegs       ; Reload the struct's address.
	LDMIA R0, {R1-R14}^       ; Restore the registers and increment the pointer.
	ADD R0,R0,#0x38		; increment the pointer (4*14 registers)

	;; Restore the CPSR
	LDMIA R0, {R0}             ; Restore to the register.
	MSR   CPSR_cxsf,R0         ; Recover the CPSR itself.
	MEND

                ENTRY

Reset_Handler
		;Firstly, to store context of boot33 before they are destroyed, 
		;r0 and r1 is not protected, so set them as input parameters.
saveContext SAVECONTEXT  ;r0 and r1 are input parameters before calling context.
				
; normal vector address selected
                MRC   p15, 0, r1, c1, c0, 0
                BIC   r1, r1, #0x2000
                MCR   p15, 0, r1, c1, c0, 0

;==================================================================
; Disable MPU and caches
;==================================================================

; Disable MPU and cache in case it was left enabled from an earlier run
; This does not need to be done from a cold reset

	MRC 	p15, 0, r0, c1, c0, 0		; Read CP15 Control Register
	BIC 	r0, r0, #0x05				; Disable MPU (M bit) and data cache (C bit)
	BIC 	r0, r0, #0x1000 			; Disable instruction cache (I bit)
	DSB 								; Ensure all previous loads/stores have completed
	MCR 	p15, 0, r0, c1, c0, 0		; Write CP15 Control Register
	ISB 								; Ensure subsequent insts execute wrt new MPU settings

;==================================================================
; Disable Branch prediction
;==================================================================

; In the Cortex-R5, the Z-bit of the SCTLR does not control the program flow prediction.
; Some control bits in the ACTLR control the program flow and prefetch features instead.
; These are enabled by default, but are shown here for completeness.

	MRC 	p15, 0, r0, c1, c0, 1		; Read ACTLR
	ORR 	r0, r0, #(0x1 << 17)		; Enable RSDIS bit 17 to disable the return stack
	ORR 	r0, r0, #(0x1 << 16)		; Clear BP bit 15 and set BP bit 16:
	BIC 	r0, r0, #(0x1 << 15)		; Branch always not taken and history table updates disabled
	MCR 	p15, 0, r0, c1, c0, 1		; Write ACTLR


; Setup Stack for each mode

				LDR 	R0, =Stack_Top

;  Enter Undefined Instruction Mode and set its Stack Pointer
				MSR 	CPSR_c, #Mode_UND:OR:I_Bit:OR:F_Bit
				MOV 	SP, R0
				SUB 	R0, R0, #UND_Stack_Size

;  Enter Abort Mode and set its Stack Pointer
				MSR 	CPSR_c, #Mode_ABT:OR:I_Bit:OR:F_Bit
				MOV 	SP, R0
				SUB 	R0, R0, #ABT_Stack_Size

;  Enter FIQ Mode and set its Stack Pointer
				MSR 	CPSR_c, #Mode_FIQ:OR:I_Bit:OR:F_Bit
				MOV 	SP, R0
				SUB 	R0, R0, #FIQ_Stack_Size

;  Enter IRQ Mode and set its Stack Pointer
				MSR 	CPSR_c, #Mode_IRQ:OR:I_Bit:OR:F_Bit
				MOV 	SP, R0
				SUB 	R0, R0, #IRQ_Stack_Size

;  Enter Supervisor Mode and set its Stack Pointer
				MSR 	CPSR_c, #Mode_SVC:OR:I_Bit:OR:F_Bit
				MOV 	SP, R0

;  Open Interrupt 
				MRS 	r0, cpsr
				BIC 	r0, r0, #0xc0
				MSR 	cpsr_c, r0




;==================================================================
; Cache invalidation
;==================================================================

	DSB 				; Complete all outstanding explicit memory operations

	MOV 	r0, #0

	MCR 	p15, 0, r0, c7, c5, 0		; Invalidate entire instruction cache
	MCR 	p15, 0, r0, c15, c5, 0		; Invalidate entire data cache

;==================================================================
; Enable Branch prediction
;==================================================================

; In the Cortex-R5, the Z-bit of the SCTLR does not control the program flow prediction.
; Some control bits in the ACTLR control the program flow and prefetch features instead.
; These are enabled by default, but are shown here for completeness.

	MRC 	p15, 0, r0, c1, c0, 1		; Read ACTLR
	BIC 	r0, r0, #(0x1 << 17)		; Clear RSDIS bit 17 to enable return stack
	BIC 	r0, r0, #(0x1 << 16)		; Clear BP bit 15 and BP bit 16:
	BIC 	r0, r0, #(0x1 << 15)		; Normal operation, BP is taken from the global history table.
	MCR 	p15, 0, r0, c1, c0, 1		; Write ACTLR

;*********************************************************************************
; Initialize memory required by C code
;**********************************************************************************
	IMPORT ||Load$$CODE$$Base||
	IMPORT ||Image$$CODE$$Base||
	IMPORT ||Image$$CODE$$Length||
	
	LDR r0, =||Load$$CODE$$Base||
	LDR r1, =||Image$$CODE$$Base||
	LDR r2, =||Image$$CODE$$Length||
	ADD r2, r2, #3
	MOV r2, r2, LSR #2
	CMP r2, #0
	BEQ copy_itcm
CopyCODE	
	LDR r3, [r0], #4
	STR r3, [r1], #4
	SUBS r2, r2, #1
	BNE CopyCODE

copy_itcm
	IMPORT ||Load$$ITCM$$Base||
	IMPORT ||Image$$ITCM$$Base||
	IMPORT ||Image$$ITCM$$Length||

	LDR r0, =||Load$$ITCM$$Base||
	LDR r1, =||Image$$ITCM$$Base||
	LDR r2, =||Image$$ITCM$$Length||
	ADD r2, r2, #3
	MOV r2, r2, LSR #2
	CMP r2, #0
	BEQ copy_rw
COPYITCM
	LDR r3, [r0], #4
	STR r3, [r1], #4
	SUBS r2, r2, #1
	BNE COPYITCM

copy_rw
	IMPORT ||Load$$DATA$$RW$$Base||
	IMPORT ||Image$$DATA$$RW$$Base||
	IMPORT ||Image$$DATA$$RW$$Length||
	
	LDR r0, =||Load$$DATA$$RW$$Base||
	LDR r1, =||Image$$DATA$$RW$$Base||
	LDR r2, =||Image$$DATA$$RW$$Length||

	; copy rw data from back to front
	ADD r0, r2
	SUBS r0, r0, #4
	
	ADD r1, r2
	SUBS r1, r1, #4
	
	ADD r2, r2, #3
	MOV r2, r2, LSR #2
	CMP r2, #0
	BEQ copy_zi
CopyRW	
	LDR r3, [r0], #-4
	STR r3, [r1], #-4
	SUBS r2, r2, #1
	BNE CopyRW
	
copy_zi
	IMPORT ||Image$$DATA$$ZI$$Base||
	IMPORT ||Image$$DATA$$ZI$$Length||
	
	LDR r1, =||Image$$DATA$$ZI$$Base||
	LDR r2, =||Image$$DATA$$ZI$$Length||
	ADD r2, r2, #3
	MOV r2, r2, LSR #2
	CMP r2, #0
	BEQ copy_end
	MOV r0, #0
CopyZI	
	STR r0, [r1], #4
	SUBS r2, r2, #1
	BNE CopyZI
copy_end


	IMPORT logo
	IMPORT printlog
	BL logo    ;to show logo and execute PrepareToExecuteCp
	;BL printlog

	;To restore the context of boot33 before back to run boot33 code.
	;SHOULD NOT destroy registers any more before exit to boot33.
restoreContext RESTORECONTEXT
	NOP
	BX    lr       ;return to boot33
	
LOOPFOREVER  B		LOOPFOREVER				; forever loop

	EXPORT getLR_reg
	EXPORT getSP_reg
getLR_reg 
	mov r0, lr
	bx lr
getSP_reg 
	mov r0, SP
	bx lr
	
;************************************************************
; DisableIrqInterrupts
;************************************************************

DisableIrqInterrupts
	STMFD		SP!, {R0-R4, LR}
   	MRS    	r0,CPSR        ; get the processor status
   	ORR    	r0,r0,#0x80    ; Disable IRQ interrupts
   	MSR    	cpsr_cf,r0     ; SVC 32 mode with interrupts disabled
	LDMFD   	SP!,    {R0-R4, PC}

;***********************************************************************************
;  r0 = Boot Image Load Address
;***********************************************************************************
   EXPORT TransferControl
TransferControl
	mov pc, r0

transfer_control
	DCD 0xF57FF04F	;DSB
	DCD 0xF57FF06F	;ISB
	DCD 0xF8900A00	;RFEIA r0

	EXPORT sctlr_get
sctlr_get
	mrc p15, 0, r0, c1, c0, 0
	bx		lr

	EXPORT sctlr_set
sctlr_set
	mcr p15, 0, r0, c1, c0, 0
	DCD 0xF57FF06F	;ISB
	bx		lr
	
	EXPORT mpu_get_region_num
mpu_get_region_num
	mrc p15, 0, r0, c6, c2, 0
	bx		lr
	
	EXPORT mpu_set_region_num
mpu_set_region_num
	mcr p15, 0, r0, c6, c2, 0
	DCD 0xF57FF06F	;ISB
	bx		lr

	EXPORT mpu_get_region_base_addr
mpu_get_region_base_addr
	mrc p15, 0, r0, c6, c1, 0
	bx		lr
	
	EXPORT mpu_set_region_base_addr
mpu_set_region_base_addr
	mcr p15, 0, r0, c6, c1, 0
	DCD 0xF57FF06F	;ISB
	bx		lr
	
	EXPORT mpu_get_region_size
mpu_get_region_size
	mrc p15, 0, r0, c6, c1, 2
	and		r0, r0, #0x3E
	mov		r0, r0, lsr #1
	bx		lr
	
	EXPORT mpu_set_region_size
mpu_set_region_size
	STMFD	SP!, {R0-R4, LR}
	mov 	r1, r0
	mrc 		p15, 0, r0, c6, c1, 2
	bic		r0, r0, #0x3E
	mov		r1, r1, LSL #1
	orr		r0, r0, r1
	mcr 		p15, 0, r0, c6, c1, 2
	DCD 	0xF57FF06F	;ISB
	LDMFD   	SP!,    {R0-R4, PC}
	
	EXPORT mpu_get_region_size_enable
mpu_get_region_size_enable
	mrc p15, 0, r0, c6, c1, 2
	bx		lr
	
	EXPORT mpu_get_region_access_ctrl
mpu_get_region_access_ctrl
	mrc p15, 0, r0, c6, c1, 4
	bx		lr
	
	EXPORT mpu_set_region_access_ctrl
mpu_set_region_access_ctrl
	mcr p15, 0, r0, c6, c1, 4
	DCD 0xF57FF06F	;ISB
	bx		lr
	
	EXPORT mpu_enable_region
mpu_enable_region
	STMFD	SP!, {R0-R4, LR}
	bl		mpu_set_region_num
	mrc 		p15, 0, r0, c6, c1, 2
	orr		r0, r0, #0x1 ;set bit 0 to enable
	mcr 		p15, 0, r0, c6, c1, 2
	DCD 	0xF57FF06F	;ISB
	LDMFD   	SP!,    {R0-R4, PC}
	
	EXPORT CPUCleanDCacheLine
CPUCleanDCacheLine
	DSB								;ensure ordering with previous memory access
	MCR		p15, 0, R0, c7, c10, 1
	DSB								;ensure ordering with previous memory access
	BX LR

	EXPORT CPUInvalidateDCacheLine
CPUInvalidateDCacheLine
	DSB								;ensure ordering with previous memory access
	MCR		p15, 0, R0, c7, c6, 1	;invalidate L1 Cache
	DSB								;ensure ordering with previous memory access
	BX LR
;-------------------------------------------------------

   END

