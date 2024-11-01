////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	IOF.h	:	IO macro, IO function definition																	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// I/O macro
#define		IN_B(addr)			(unsigned char)inb(addr)
#define		IN_W(addr)			(unsigned short)inw(addr)
#define		IN_D(addr)			(unsigned long)inl(addr)
#define		OUT_B(addr, val)	outb(val, addr)
#define		OUT_W(addr, val)	outw(val, addr)
#define		OUT_D(addr, val)	outl(val, addr)

#define		BREAK				_asm{int 1}

#define		OFSET_AI			0x00
#define		OFSET_AO			0x10
#define		OFSET_DI			0x20
#define		OFSET_DO			0x30
#define		OFSET_CNT			0x40
#define		OFSET_MEM			0x50
#define		OFSET_ECU			0x80

// Common command
void			IOF_ResetDevice(unsigned short BoardNo, unsigned int Address);
void			IOF_OutByte(unsigned int Address, unsigned char Data);
void			IOF_OutWord(unsigned int Address, unsigned short Data);
void			IOF_OutDword(unsigned int Address, unsigned long Data);
unsigned char	IOF_InpByte(unsigned int Address);
unsigned short	IOF_InpWord(unsigned int Address);
unsigned long	IOF_InpDword(unsigned int Address);

// ECU command
#define	ECU_RESET			0	//	Reset
#define	ECU_ENABLEINT		1	//	Enable interrupt mask setting
#define	ECU_DISABLEINT		2	//	Disable interrupt mask setting
#define	ECU_CONNECT			3	//	I/O signal connection
#define	ECU_COMBINATION		4	//	Combinational circuit
#define	ECU_GENERALCOMMAND1	5	//	General command 1
#define	ECU_GENERALCOMMAND2	6	//	General command 2
#define	ECU_GENERALCOMMAND3	7	//	General command 3
#define	ECU_GENERALCOMMAND4	8	//	General command 4
#define	ECU_DELAYTIME		9	//	Delay time setting
#define	ECU_EMERGENCY		10	//	Abnormal stop
#define	ECU_AIEMERGENCY		16	//	AI abnormal stop setting
#define	ECU_AOEMERGENCY		17	//	AO abnormal stop setting
#define	ECU_SRAMTEST		18	//	SRAM test
#define	ECU_SYNCBUS			24	//	Synchronous bus Master/Slave setting

void			IOF_ResetEcu(unsigned short BoardNo, unsigned int Address);
unsigned short	IOF_GetFlags(unsigned short BoardNo, unsigned int Address);
unsigned long	IOF_GetMemFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetMemFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetCntFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetCntFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetDoFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetDoFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetDiFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetDiFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetAoFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetAoFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetAiFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetAiFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetSigFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetSigFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
unsigned long	IOF_GetBmFlag(unsigned short BoardNo, unsigned int Address);
void			IOF_ResetBmFlag(unsigned short BoardNo, unsigned int Address, unsigned long Flag);
void			IOF_SetEcuCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetEcuCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetEcuCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetEcuCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);
void			IOF_ResetFlags(unsigned short BoardNo, unsigned int Address, unsigned long Flags);

// MEM command
#define	MEM_ALLRESET		0	//	Reset
#define	MEM_AITRANSFERTYPE	1	//	AI transfer
#define	MEM_AOTRANSFERTYPE	2	//	AO transfer
#define	MEM_AIWT			3	//	AI write pointer
#define	MEM_AIRT			4	//	AI read pointer
#define	MEM_AOWT			5	//	AO write pointer
#define	MEM_AORT			6	//	AO read pointer
#define	MEM_AICLEAR			7	//	AI memory clear
#define	MEM_AOCLEAR			8	//	AO memory clear
#define	MEM_AIMEMORYTYPE	9	//	AI memory type
#define	MEM_AOMEMORYTYPE	10	//	AO memory type
#define	MEM_AIFIFOREAD		11	//	AI FIFO counter monitoring
#define	MEM_AOFIFOREAD		12	//	AO FIFO counter monitoring
#define	MEM_AIFIFO1DEBUG	13	//	AO FIFO counter1 monitoring (for debug)
#define	MEM_AIFIFO2DEBUG	14	//	AO FIFO counter2 monitoring (for debug)
#define	MEM_DDRTEST			15	//	DDR test mode
#define	MEM_AICOMPTYPE		16	//	AI memory comparison type
#define	MEM_AICOMPDATA		17	//	AI memory comparison data
#define	MEM_AITRGWP			18	//	AI trigger write pointer address
#define	MEM_AITRGRP			19	//	AI trigger read pointer address
#define	MEM_AIMAXWP			20	//	AI write pointer upper limit address
#define	MEM_AIATTACHEDDATA	21	//	AI attached data
#define	MEM_AISTOPTRGDATA	22	//	Number of AI switching trigger data
#define	MEM_AISWITCH		24	//	AI W/R switching point setting
#define	MEM_AOCOMPTYPE		32	//	Ao memory comparison type
#define	MEM_AOCOMPDATA		33	//	Ao memory comparison data
#define	MEM_AOTRGWP			34	//	Ao trigger write pointer address
#define	MEM_AOTRGRP			35	//	Ao trigger read pointer address
#define	MEM_AOMAXRP			36	//	AO read pointer upper limit address
#define	MEM_AOATTACHEDDATA	37	//	AO attached data
#define	MEM_AOBANKRP		38	//	AO bank switching RP

void			IOF_ResetMem(unsigned short BoardNo, unsigned int Address);
unsigned long	IOF_GetMemStatus(unsigned short BoardNo, unsigned int Address);
void 			IOF_SetMemCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetMemCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void 			IOF_SetMemCommandD2(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data1, unsigned long Data2);
unsigned long	IOF_GetMemCommandD2(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data1);
void			IOF_SetMemCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetMemCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);

// AI command
#define	AI_RESET			0	//	Reset
#define	AI_OPEN				1	//	Gate open
#define	AI_CLOSE			2	//	Gate close
#define	AI_CLOCK			3	//	Internal clock
#define	AI_SCANCLOCK		4	//	Scan interval
#define	AI_CHANNELS			5	//	Number of channels
#define	AI_SEQUENCE			6	//	Conversion sequence
#define	AI_METHOD			7	//	Input method
#define	AI_RANGE			8	//	Range
#define	AI_BTSAMPLING		9	//	Sampling before trigger
#define	AI_ATSAMPLING		10	//	Sampling after trigger
#define	AI_REPEAT			11	//	Repeat
#define	AI_CHANNELMODE		12	//	Channel mode
#define	AI_CHANNELGATE		13	//	Channel gate
#define	AI_ADJUSTMENT		32	//	Calibration
#define	AI_EEPROM			33	//	Adjustment data
#define	AI_LEVELTRGTYPE		34	//	Level trigger comparison type
#define	AI_LEVELTRGCHANNEL	35	//	Level trigger monitoring channel
#define	AI_LEVELTRGSTATE	36	//	Level trigger state maintaining times
#define	AI_LEVEL			37	//	Level comparison
#define	AI_COMPSAMPLING		38	//	Comparison sampling times
#define	AI_COMPREPEAT		39	//	Comparison repeat times

void			IOF_ResetAi(unsigned short BoardNo, unsigned int Address);
unsigned short	IOF_GetAiData(unsigned short BoardNo, unsigned int Address);
unsigned long	IOF_GetAiStatus(unsigned short BoardNo, unsigned int Address);
void			IOF_OpenAiGate(unsigned short BoardNo, unsigned int Address);
void			IOF_CloseAiGate(unsigned short BoardNo, unsigned int Address);
void			IOF_SetAiCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetAiCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetAiCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetAiCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);
unsigned short	IOF_SetAiEEPROM(unsigned short BoardNo, unsigned int Address, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetAiEEPROM(unsigned short BoardNo, unsigned int Address, unsigned short DataLow, unsigned short * DataHigh);

// AO command
#define	AO_RESET			0	//	Reset
#define	AO_OPEN				1	//	Gate open
#define	AO_CLOSE			2	//	Gate close
#define	AO_CLOCK			3	//	Internal clock
#define	AO_CHANNELS			5	//	Number of channels
#define	AO_SEQUENCE			6	//	Conversion sequence
#define	AO_RANGE			8	//	Range
#define	AO_BTSAMPLING		9	//	Sampling before trigger
#define	AO_ATSAMPLING		10	//	Sampling after trigger
#define	AO_REPEAT			11	//	Repeat
#define	AO_CHANNELMODE		12	//	Channel mode
#define	AO_REPEATCOUNT		13	//	Repeat count source
#define	AO_ADJUSTMENT		32	//	Calibration
#define	AO_EEPROM			33	//	Adjustment data
#define	AO_LEVELTRGTYPE		34	//	Level trigger comparison type
#define	AO_LEVELTRGCHANNEL	35	//	Level trigger monitoring channel
#define	AO_LEVELTRGSTATE	36	//	Level trigger state maintaining times
#define	AO_LEVEL			37	//	Level comparison
#define	AO_COMPSAMPLING		38	//	Comparison sampling times
#define	AO_COMPREPEAT		39	//	Comparison repeat times
#define	AO_EX1				40	//	After the update stop process - Method setting
#define	AO_EX2				41	//	After the update stop process - Final output value
#define	AO_EX3				42	//	After the update stop process - HOLD time

void			IOF_ResetAo(unsigned short BoardNo, unsigned int Address);
void			IOF_SetAoData(unsigned short BoardNo, unsigned int Address, unsigned short Data);
unsigned short	IOF_GetAoData(unsigned short BoardNo, unsigned int Address);
unsigned long	IOF_GetAoStatus(unsigned short BoardNo, unsigned int Address);
void			IOF_OpenAoGate(unsigned short BoardNo, unsigned int Address);
void			IOF_CloseAoGate(unsigned short BoardNo, unsigned int Address);
void			IOF_SetAoCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetAoCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetAoCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetAoCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);
unsigned short	IOF_SetAoEEPROM(unsigned short BoardNo, unsigned int Address, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetAoEEPROM(unsigned short BoardNo, unsigned int Address, unsigned short DataLow, unsigned short * DataHigh);

// CNT command
#define	CNT_RESET			0	//	Reset
#define	CNT_OPEN			1	//	Gate open
#define	CNT_CLOSE			2	//	Gate close
#define	CNT_CLOCK			3	//	Internal clock
#define	CNT_MODE			4	//	Input condition
#define	CNT_CURRENT			5	//	Current setting
#define	CNT_LOAD			6	//	Load value setting
#define	CNT_COMPARISON		7	//	Comparison count value setting
#define	CNT_EMERGENCY		8	//	Abnormality detection

unsigned long	IOF_GetCntStatus(unsigned short BoardNo, unsigned int Address, unsigned short Channel);
void			IOF_SetCntCommandD1(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetCntCommandD1(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetCntCommandD2(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data1, unsigned long Data2);
unsigned long	IOF_GetCntCommandD2(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data1);

// DI command
#define	DI_RESET			0	//	Reset
#define	DI_EDGE				1	//	Edge detection
#define	DI_FILTER			2	//	Filter
#define	DI_DIRECTION		3	//	Direction
#define	DI_SERIAL			4	//	Serial pattern trigger
#define	DI_PARALLELL		5	//	Parallel pattern trigger

void			IOF_ResetDi(unsigned short BoardNo, unsigned int Address);
unsigned long	IOF_GetDiData(unsigned short BoardNo, unsigned int Address);
void			IOF_SetDiMask(unsigned short BoardNo, unsigned int Address, unsigned long Data);
void			IOF_SetDiCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetDiCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetDiCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetDiCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);

// DO command
#define	DO_RESET			0	//	Reset
#define	DO_CFG				1	//	Output setting
#define	DO_SIGCFG			2	//	Output status setting
#define	DO_PLS				3	//	Pulse width
#define	DO_SERIAL			4	//	Serial pattern trigger
#define	DO_PARALLELL		5	//	Parallel pattern trigger
#define	DO_SERIALCFG		6	//	Serial output setting
#define	DO_PWM				7	//	PWM output

void			IOF_ResetDo(unsigned short BoardNo, unsigned int Address);
void			IOF_SetDoData(unsigned short BoardNo, unsigned int Address, unsigned long DoData);
unsigned long	IOF_GetDoData(unsigned short BoardNo, unsigned int Address);
void			IOF_SetDoMask(unsigned short BoardNo, unsigned int Address, unsigned long Mask);
unsigned long	IOF_GetDoMask(unsigned short BoardNo, unsigned int Address);
void			IOF_SetDoCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned long Data);
unsigned long	IOF_GetDoCommandD(unsigned short BoardNo, unsigned int Address, unsigned long Command);
void			IOF_SetDoCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow, unsigned short DataHigh);
unsigned short	IOF_GetDoCommandW(unsigned short BoardNo, unsigned int Address, unsigned long Command, unsigned short DataLow);


