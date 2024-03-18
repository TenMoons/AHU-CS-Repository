;-----------------------------------------------------------------------------
;	File:		FX2regs.inc
;	Contents:	EZ-USB FX2 register declarations and bit mask definitions.
;				This file is the equivalent of fx2regs.h but for assembley code
;				Do not modify one without modifying the other.
;
;	Copyright (c) 2000 Cypress Semiconductor, All rights reserved
;-----------------------------------------------------------------------------

GPIF_WAVE_DATA       XDATA 0xE400   ;
RES_WAVEDATA_END     XDATA 0xE480   ;

; General Configuration

CPUCS               XDATA 0xE600  ; Control & Status
IFCONFIG            XDATA 0xE601  ; Interface Configuration
PINFLAGSAB          XDATA 0xE602  ; FIFO FLAGA and FLAGB Assignments
PINFLAGSCD          XDATA 0xE603  ; FIFO FLAGC and FLAGD Assignments
FIFORESET           XDATA 0xE604  ; Restore FIFOS to default state
BREAKPT             XDATA 0xE605  ; Breakpoint
BPADDRH             XDATA 0xE606  ; Breakpoint Address H
BPADDRL             XDATA 0xE607  ; Breakpoint Address L
UART230             XDATA 0xE608  ; 230 Kbaud clock for T0,T1,T2
FIFOPINPOLAR        XDATA 0xE609  ; FIFO polarities
REVID               XDATA 0xE60A  ; Chip Revision
REVCTL              XDATA 0xE60B  ; Chip Revision Control

; Endpoint Configuration

EP1OUTCFG           XDATA 0xE610  ; Endpoint 1-OUT Configuration
EP1INCFG            XDATA 0xE611  ; Endpoint 1-IN Configuration
EP2CFG              XDATA 0xE612  ; Endpoint 2 Configuration
EP4CFG              XDATA 0xE613  ; Endpoint 4 Configuration
EP6CFG              XDATA 0xE614  ; Endpoint 6 Configuration
EP8CFG              XDATA 0xE615  ; Endpoint 8 Configuration
EP2FIFOCFG          XDATA 0xE618  ; Endpoint 2 FIFO configuration
EP4FIFOCFG          XDATA 0xE619  ; Endpoint 4 FIFO configuration
EP6FIFOCFG          XDATA 0xE61A  ; Endpoint 6 FIFO configuration
EP8FIFOCFG          XDATA 0xE61B  ; Endpoint 8 FIFO configuration
EP2AUTOINLENH       XDATA 0xE620  ; Endpoint 2 Packet Length H (IN only)
EP2AUTOINLENL       XDATA 0xE621  ; Endpoint 2 Packet Length L (IN only)
EP4AUTOINLENH       XDATA 0xE622  ; Endpoint 4 Packet Length H (IN only)
EP4AUTOINLENL       XDATA 0xE623  ; Endpoint 4 Packet Length L (IN only)
EP6AUTOINLENH       XDATA 0xE624  ; Endpoint 6 Packet Length H (IN only)
EP6AUTOINLENL       XDATA 0xE625  ; Endpoint 6 Packet Length L (IN only)
EP8AUTOINLENH       XDATA 0xE626  ; Endpoint 8 Packet Length H (IN only)
EP8AUTOINLENL       XDATA 0xE627  ; Endpoint 8 Packet Length L (IN only)
EP2FIFOPFH          XDATA 0xE630  ; EP2 Programmable Flag trigger H
EP2FIFOPFL          XDATA 0xE631  ; EP2 Programmable Flag trigger L
EP4FIFOPFH          XDATA 0xE632  ; EP4 Programmable Flag trigger H
EP4FIFOPFL          XDATA 0xE633  ; EP4 Programmable Flag trigger L
EP6FIFOPFH          XDATA 0xE634  ; EP6 Programmable Flag trigger H
EP6FIFOPFL          XDATA 0xE635  ; EP6 Programmable Flag trigger L
EP8FIFOPFH          XDATA 0xE636  ; EP8 Programmable Flag trigger H
EP8FIFOPFL          XDATA 0xE637  ; EP8 Programmable Flag trigger L
EP2ISOINPKTS        XDATA 0xE640  ; EP2 (if ISO) IN Packets per frame (1-3)
EP4ISOINPKTS        XDATA 0xE641  ; EP4 (if ISO) IN Packets per frame (1-3)
EP6ISOINPKTS        XDATA 0xE642  ; EP6 (if ISO) IN Packets per frame (1-3)
EP8ISOINPKTS        XDATA 0xE643  ; EP8 (if ISO) IN Packets per frame (1-3)
INPKTEND            XDATA 0xE648  ; Force IN Packet End
OUTPKTEND           XDATA 0xE649  ; Force OUT Packet End

; Interrupts

EP2FIFOIE           XDATA 0xE650  ; Endpoint 2 Flag Interrupt Enable
EP2FIFOIRQ          XDATA 0xE651  ; Endpoint 2 Flag Interrupt Request
EP4FIFOIE           XDATA 0xE652  ; Endpoint 4 Flag Interrupt Enable
EP4FIFOIRQ          XDATA 0xE653  ; Endpoint 4 Flag Interrupt Request
EP6FIFOIE           XDATA 0xE654  ; Endpoint 6 Flag Interrupt Enable
EP6FIFOIRQ          XDATA 0xE655  ; Endpoint 6 Flag Interrupt Request
EP8FIFOIE           XDATA 0xE656  ; Endpoint 8 Flag Interrupt Enable
EP8FIFOIRQ          XDATA 0xE657  ; Endpoint 8 Flag Interrupt Request
IBNIE               XDATA 0xE658  ; IN-BULK-NAK Interrupt Enable
IBNIRQ              XDATA 0xE659  ; IN-BULK-NAK interrupt Request
NAKIE               XDATA 0xE65A  ; Endpoint Ping NAK interrupt Enable
NAKIRQ              XDATA 0xE65B  ; Endpoint Ping NAK interrupt Request
USBIE               XDATA 0xE65C  ; USB Int Enables
USBIRQ              XDATA 0xE65D  ; USB Interrupt Requests
EPIE                XDATA 0xE65E  ; Endpoint Interrupt Enables
EPIRQ               XDATA 0xE65F  ; Endpoint Interrupt Requests
GPIFIE              XDATA 0xE660  ; GPIF Interrupt Enable
GPIFIRQ             XDATA 0xE661  ; GPIF Interrupt Request
USBERRIE            XDATA 0xE662  ; USB Error Interrupt Enables
USBERRIRQ           XDATA 0xE663  ; USB Error Interrupt Requests
ERRCNTLIM           XDATA 0xE664  ; USB Error counter and limit
CLRERRCNT           XDATA 0xE665  ; Clear Error Counter EC[3..0]
INT2IVEC            XDATA 0xE666  ; Interupt 2 (USB) Autovector
INT4IVEC            XDATA 0xE667  ; Interupt 4 (FIFOS & GPIF) Autovector
INTSETUP            XDATA 0xE668  ; Interrupt 2&4 Setup

; Input/Output

PORTACFG            XDATA 0xE670  ; I/O PORTA Alternate Configuration
PORTCCFG            XDATA 0xE671  ; I/O PORTC Alternate Configuration
PORTECFG            XDATA 0xE672  ; I/O PORTE Alternate Configuration
I2CS                XDATA 0xE678  ; Control & Status
I2DAT               XDATA 0xE679  ; Data
I2CTL               XDATA 0xE67A  ; I2C Control
EXTAUTODAT1         XDATA 0xE67B  ; Autoptr1 MOVX access
EXTAUTODAT2         XDATA 0xE67C  ; Autoptr2 MOVX access

; USB Control

USBCS               XDATA 0xE680  ; USB Control & Status
SUSPEND             XDATA 0xE681  ; Put chip into suspend
WAKEUPCS            XDATA 0xE682  ; Wakeup source and polarity
TOGCTL              XDATA 0xE683  ; Toggle Control
USBFRAMEH           XDATA 0xE684  ; USB Frame count H
USBFRAMEL           XDATA 0xE685  ; USB Frame count L
MICROFRAME          XDATA 0xE686  ; Microframe count, 0-7
FNADDR              XDATA 0xE687  ; USB Function address

; Endpoints

EP0BCH              XDATA 0xE68A  ; Endpoint 0 Byte Count H
EP0BCL              XDATA 0xE68B  ; Endpoint 0 Byte Count L
EP1OUTBC            XDATA 0xE68D  ; Endpoint 1 OUT Byte Count
EP1INBC             XDATA 0xE68F  ; Endpoint 1 IN Byte Count
EP2BCH              XDATA 0xE690  ; Endpoint 2 Byte Count H
EP2BCL              XDATA 0xE691  ; Endpoint 2 Byte Count L
EP4BCH              XDATA 0xE694  ; Endpoint 4 Byte Count H
EP4BCL              XDATA 0xE695  ; Endpoint 4 Byte Count L
EP6BCH              XDATA 0xE698  ; Endpoint 6 Byte Count H
EP6BCL              XDATA 0xE699  ; Endpoint 6 Byte Count L
EP8BCH              XDATA 0xE69C  ; Endpoint 8 Byte Count H
EP8BCL              XDATA 0xE69D  ; Endpoint 8 Byte Count L
EP0CS               XDATA 0xE6A0  ; Endpoint  Control and Status
EP1OUTCS            XDATA 0xE6A1  ; Endpoint 1 OUT Control and Status
EP1INCS             XDATA 0xE6A2  ; Endpoint 1 IN Control and Status
EP2CS               XDATA 0xE6A3  ; Endpoint 2 Control and Status
EP4CS               XDATA 0xE6A4  ; Endpoint 4 Control and Status
EP6CS               XDATA 0xE6A5  ; Endpoint 6 Control and Status
EP8CS               XDATA 0xE6A6  ; Endpoint 8 Control and Status
EP2FIFOFLGS         XDATA 0xE6A7  ; Endpoint 2 Flags
EP4FIFOFLGS         XDATA 0xE6A8  ; Endpoint 4 Flags
EP6FIFOFLGS         XDATA 0xE6A9  ; Endpoint 6 Flags
EP8FIFOFLGS         XDATA 0xE6AA  ; Endpoint 8 Flags
EP2FIFOBCH          XDATA 0xE6AB  ; EP2 FIFO total byte count H
EP2FIFOBCL          XDATA 0xE6AC  ; EP2 FIFO total byte count L
EP4FIFOBCH          XDATA 0xE6AD  ; EP4 FIFO total byte count H
EP4FIFOBCL          XDATA 0xE6AE  ; EP4 FIFO total byte count L
EP6FIFOBCH          XDATA 0xE6AF  ; EP6 FIFO total byte count H
EP6FIFOBCL          XDATA 0xE6B0  ; EP6 FIFO total byte count L
EP8FIFOBCH          XDATA 0xE6B1  ; EP8 FIFO total byte count H
EP8FIFOBCL          XDATA 0xE6B2  ; EP8 FIFO total byte count L
SUDPTRH             XDATA 0xE6B3  ; Setup Data Pointer high address byte
SUDPTRL             XDATA 0xE6B4  ; Setup Data Pointer low address byte
SUDPTRCTL           XDATA 0xE6B5  ; Setup Data Pointer Auto Mode
SETUPDAT            XDATA 0xE6B8  ; 8 bytes of SETUP data

; GPIF

GPIFWFSELECT        XDATA 0xE6C0  ; Waveform Selector
GPIFIDLECS          XDATA 0xE6C1  ; GPIF Done, GPIF IDLE drive mode
GPIFIDLECTL         XDATA 0xE6C2  ; Inactive Bus, CTL states
GPIFCTLCFG          XDATA 0xE6C3  ; CTL OUT pin drive
GPIFADRH            XDATA 0xE6C4  ; GPIF Address H
GPIFADRL            XDATA 0xE6C5  ; GPIF Address L


GPIFTCB3            XDATA 0xE6CE  ; GPIF Transaction Count Byte 3
GPIFTCB2            XDATA 0xE6CF  ; GPIF Transaction Count Byte 2
GPIFTCB1            XDATA 0xE6D0  ; GPIF Transaction Count Byte 1
GPIFTCB0            XDATA 0xE6D1  ; GPIF Transaction Count Byte 0


EP2GPIFTCH          EQU  GPIFTCB1 ; these are here for backwards compatibility
EP2GPIFTCL          EQU  GPIFTCB0 ; before REVE silicon (ie. REVB and REVD)
EP4GPIFTCH          EQU  GPIFTCB1 ; these are here for backwards compatibility
EP4GPIFTCL          EQU  GPIFTCB0 ; before REVE silicon (ie. REVB and REVD)
EP6GPIFTCH          EQU  GPIFTCB1 ; these are here for backwards compatibility
EP6GPIFTCL          EQU  GPIFTCB0 ; before REVE silicon (ie. REVB and REVD)
EP8GPIFTCH          EQU  GPIFTCB1 ; these are here for backwards compatibility
EP8GPIFTCL          EQU  GPIFTCB0 ; before REVE silicon (ie. REVB and REVD)


; EP2GPIFTCH        XDATA 0xE6D0  ; EP2 GPIF Transaction Count High
; EP2GPIFTCL        XDATA 0xE6D1  ; EP2 GPIF Transaction Count Low
EP2GPIFFLGSEL       XDATA 0xE6D2  ; EP2 GPIF Flag select
EP2GPIFPFSTOP       XDATA 0xE6D3  ; Stop GPIF EP2 transaction on prog. flag
EP2GPIFTRIG         XDATA 0xE6D4  ; EP2 FIFO Trigger
; EP4GPIFTCH        XDATA 0xE6D8  ; EP4 GPIF Transaction Count High
; EP4GPIFTCL        XDATA 0xE6D9  ; EP4 GPIF Transactionr Count Low
EP4GPIFFLGSEL       XDATA 0xE6DA  ; EP4 GPIF Flag select
EP4GPIFPFSTOP       XDATA 0xE6DB  ; Stop GPIF EP4 transaction on prog. flag
EP4GPIFTRIG         XDATA 0xE6DC  ; EP4 FIFO Trigger
; EP6GPIFTCH        XDATA 0xE6E0  ; EP6 GPIF Transaction Count High
; EP6GPIFTCL        XDATA 0xE6E1  ; EP6 GPIF Transaction Count Low
EP6GPIFFLGSEL       XDATA 0xE6E2  ; EP6 GPIF Flag select
EP6GPIFPFSTOP       XDATA 0xE6E3  ; Stop GPIF EP6 transaction on prog. flag
EP6GPIFTRIG         XDATA 0xE6E4  ; EP6 FIFO Trigger
; EP8GPIFTCH        XDATA 0xE6E8  ; EP8 GPIF Transaction Count High
; EP8GPIFTCL        XDATA 0xE6E9  ; EP8GPIF Transaction Count Low
EP8GPIFFLGSEL       XDATA 0xE6EA  ; EP8 GPIF Flag select
EP8GPIFPFSTOP       XDATA 0xE6EB  ; Stop GPIF EP8 transaction on prog. flag
EP8GPIFTRIG         XDATA 0xE6EC  ; EP8 FIFO Trigger
XGPIFSGLDATH        XDATA 0xE6F0  ; GPIF Data H (16-bit mode only)
XGPIFSGLDATLX       XDATA 0xE6F1  ; Read/Write GPIF Data L & trigger transac
XGPIFSGLDATLNOX     XDATA 0xE6F2  ; Read GPIF Data L, no transac trigger
GPIFREADYCFG        XDATA 0xE6F3  ; Internal RDY,Sync/Async, RDY5CFG
GPIFREADYSTAT       XDATA 0xE6F4  ; RDY pin states
GPIFABORT           XDATA 0xE6F5  ; Abort GPIF cycles

; UDMA

FLOWSTATE           XDATA 0xE6C6  ; Defines GPIF flow state
FLOWLOGIC           XDATA 0xE6C7  ; Defines flow/hold decision criteria
FLOWEQ0CTL          XDATA 0xE6C8  ; CTL states during active flow state
FLOWEQ1CTL          XDATA 0xE6C9  ; CTL states during hold flow state
FLOWSTB             XDATA 0xE6CB  ; CTL/RDY Signal to use as master data strobe 
FLOWEDGE            XDATA 0xE6CC  ; Defines active master strobe edge
FLOWSTBHPERIOD      XDATA 0xE6CD  ; Half Period of output master strobe
GPIFHOLDAMOUNT      XDATA 0xE60C  ; Data delay shift 
UDMACRCH            XDATA 0xE67D  ; CRC Upper byte
UDMACRCL            XDATA 0xE67E  ; CRC Lower byte
UDMACRCQUAL         XDATA 0xE67F  ; UDMA In only, host terminated use only


; Debug/Test

DBUG                XDATA 0xE6F8  ; Debug
TESTCFG             XDATA 0xE6F9  ; Test configuration
USBTEST             XDATA 0xE6FA  ; USB Test Modes
CT1                 XDATA 0xE6FB  ; Chirp Test--Override
CT2                 XDATA 0xE6FC  ; Chirp Test--FSM
CT3                 XDATA 0xE6FD  ; Chirp Test--Control Signals
CT4                 XDATA 0xE6FE  ; Chirp Test--Inputs

; Endpoint Buffers

EP0BUF              XDATA 0xE740  ; EP0 IN-OUT buffer
EP10UTBUF           XDATA 0xE780  ; EP1-OUT buffer
EP1INBUF            XDATA 0xE7C0  ; EP1-IN buffer
EP2FIFOBUF          XDATA 0xF000  ; 512/1024-byte EP2 buffer (IN or OUT)
EP4FIFOBUF          XDATA 0xF400  ; 512 byte EP4 buffer (IN or OUT)
EP6FIFOBUF          XDATA 0xF800  ; 512/1024-byte EP6 buffer (IN or OUT)
EP8FIFOBUF          XDATA 0xFC00  ; 512 byte EP8 buffer (IN or OUT)

;/*-----------------------------------------------------------------------------
;  Special Function Registers (SFRs)
;  The byte registers and bits defined in the following list are based
;  on the Synopsis definition of the 8051 Special Function Registers for EZ-USB. 
;   If you modify the register definitions below, please regenerate the file 
;  "ezregs.inc" which includes the same basic information for assembly inclusion.
;-----------------------------------------------------------------------------*/

IOA                 DATA 080H
SP                  DATA 081H
DPL                 DATA 082H
DPH                 DATA 083H
DPL1                DATA 084H
DPH1                DATA 085H
DPS                 DATA 086H
  ;  DPS  
  SEL   BIT 086H+0H
PCON                DATA 087H
  ;  PCON  
  ;IDLE             BIT 087H+0H
  ;STOP             BIT 087H+1H
  ;GF0              BIT 087H+2H
  ;GF1              BIT 087H+3H
  ;SMOD0            BIT 087H+7H
TCON                DATA 088H
  ;  TCON  
  IT0               BIT 088H+0H
  IE0               BIT 088H+1H
  IT1               BIT 088H+2H
  IE1               BIT 088H+3H
  TR0               BIT 088H+4H
  TF0               BIT 088H+5H
  TR1               BIT 088H+6H
  TF1               BIT 088H+7H
TMOD                DATA 089H
  ;  TMOD  
  ;M00              BIT 089H+0H
  ;M10              BIT 089H+1H
  ;CT0              BIT 089H+2H
  ;GATE0            BIT 089H+3H
  ;M01              BIT 089H+4H
  ;M11              BIT 089H+5H
  ;CT1              BIT 089H+6H
  ;GATE1            BIT 089H+7H
TL0                 DATA 08AH
TL1                 DATA 08BH
TH0                 DATA 08CH
TH1                 DATA 08DH
CKCON               DATA 08EH
  ;  CKCON  
  ;MD0              BIT 089H+0H
  ;MD1              BIT 089H+1H
  ;MD2              BIT 089H+2H
  ;T0M              BIT 089H+3H
  ;T1M              BIT 089H+4H
  ;T2M              BIT 089H+5H
;SPC_FNC            DATA 08FH               ; Was WRS in Reg320
  ;  CKCON  
  ;WRS              BIT 08FH+0H
IOB                 DATA 090H
EXIF                DATA 091H               ; EXIF Bit Values differ from Reg320
  ;  EXIF  
  ;USBINT           BIT 091H+4H
  ;I2CINT           BIT 091H+5H
  ;IE4              BIT 091H+6H
  ;IE5              BIT 091H+7H
MPAGE               DATA 092H
SCON0               DATA 098H
  ;  SCON0  
  RI                BIT 098H+0H
  TI                BIT 098H+1H
  RB8               BIT 098H+2H
  TB8               BIT 098H+3H
  REN               BIT 098H+4H
  SM2               BIT 098H+5H
  SM1               BIT 098H+6H
  SM0               BIT 098H+7H
SBUF0               DATA 099H

APTR1H              DATA 09AH
APTR1L              DATA 09BH
AUTODAT1            DATA 09CH 
AUTOPTRH2           DATA 09DH
AUTOPTRL2           DATA 09EH 
AUTODAT2            DATA 09FH
IOC                 DATA 0A0H
INT2CLR             DATA 0A1H
INT4CLR             DATA 0A2H

IE                  DATA 0A8H
  ;  IE  
  EX0               BIT 0A8H+0H
  ET0               BIT 0A8H+1H
  EX1               BIT 0A8H+2H
  ET1               BIT 0A8H+3H
  ES0               BIT 0A8H+4H
  ET2               BIT 0A8H+5H
  ES1               BIT 0A8H+6H
  EA                BIT 0A8H+7H

EP2468STAT          DATA 0AAH
  ; EP2468STAT 
  ;EP2E             BIT 0AAH+0H
  ;EP2F             BIT 0AAH+1H
  ;EP4E             BIT 0AAH+2H
  ;EP4F             BIT 0AAH+3H
  ;EP6E             BIT 0AAH+4H
  ;EP6F             BIT 0AAH+5H
  ;EP8E             BIT 0AAH+6H
  ;EP8F             BIT 0AAH+7H

EP24FIFOFLGS        DATA 0ABH
EP68FIFOFLGS        DATA 0ACH
AUTOPTRSETUP        DATA 0AFH
  ; AUTOPTRSETUP 
  ;EXTACC           BIT 0AFH+0H
  ;APTR1FZ          BIT 0AFH+1H
  ;APTR2FZ          BIT 0AFH+2H

IOD                 DATA 0B0H
IOE                 DATA 0B1H
OEA                 DATA 0B2H
OEB                 DATA 0B3H
OEC                 DATA 0B4H
OED                 DATA 0B5H
OEE                 DATA 0B6H

IP                  DATA 0B8H
  ;  IP  
  PX0               BIT 0B8H+0H
  PT0               BIT 0B8H+1H
  PX1               BIT 0B8H+2H
  PT1               BIT 0B8H+3H
  PS0               BIT 0B8H+4H
  PT2               BIT 0B8H+5H
  PS1               BIT 0B8H+6H

EP01STAT            DATA 0BAH
GPIFTRIG            DATA 0BBH
                
GPIFSGLDATH         DATA 0BDH
GPIFSGLDATLX        DATA 0BEH
GPIFSGLDATLNOX      DATA 0BFH

SCON1               DATA 0C0H
  ;  SCON1  
  RI1               BIT 0C0H+0H
  TI1               BIT 0C0H+1H
  RB81              BIT 0C0H+2H
  TB81              BIT 0C0H+3H
  REN1              BIT 0C0H+4H
  SM21              BIT 0C0H+5H
  SM11              BIT 0C0H+6H
  SM01              BIT 0C0H+7H
SBUF1               DATA 0C1H
T2CON               DATA 0C8H
  ;  T2CON  
  CP_RL2            BIT 0C8H+0H
  C_T2              BIT 0C8H+1H
  TR2               BIT 0C8H+2H
  EXEN2             BIT 0C8H+3H
  TCLK              BIT 0C8H+4H
  RCLK              BIT 0C8H+5H
  EXF2              BIT 0C8H+6H
  TF2               BIT 0C8H+7H
RCAP2L              DATA 0CAH
RCAP2H              DATA 0CBH
TL2                 DATA 0CCH
TH2                 DATA 0CDH
PSW                 DATA 0D0H
  ;  PSW  
  P                 BIT 0D0H+0H
  FL                BIT 0D0H+1H
  OV                BIT 0D0H+2H
  RS0               BIT 0D0H+3H
  RS1               BIT 0D0H+4H
  F0                BIT 0D0H+5H
  AC                BIT 0D0H+6H
  CY                BIT 0D0H+7H
EICON               DATA 0D8H;             ; Was WDCON in DS80C320H; Bit Values differ from Reg320
  ;  EICON  
  INT6              BIT 0D8H+3H
  RESI              BIT 0D8H+4H
  ERESI             BIT 0D8H+5H
  SMOD1             BIT 0D8H+7H
ACC                 DATA 0E0H
EIE                 DATA 0E8H              ; EIE Bit Values differ from Reg320
  ;  EIE  
  EUSB              BIT 0E8H+0H
  EI2C              BIT 0E8H+1H
  EIEX4             BIT 0E8H+2H
  EIEX5             BIT 0E8H+3H
  EIEX6             BIT 0E8H+4H
B                   DATA 0F0H
EIP                 DATA 0F8H              ; EIP Bit Values differ from Reg320
  ;  EIP  
  PUSB              BIT 0F8H+0H;
  PI2C              BIT 0F8H+1H;
  EIPX4             BIT 0F8H+2H;
  EIPX5             BIT 0F8H+3H;
  EIPX6             BIT 0F8H+4H;
