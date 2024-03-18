
esfr EPL   = 0xFC;
esfr EPM   = 0xFD;
esfr EPH   = 0xFE;
esfr MXCON = 0xFF;
esfr SPE   = 0xFB;

sfr  AUXR1 = 0xA2;
sfr  AUXR  = 0x8E;
sfr  SP    = 0x81;

ACC3 BIT  0xE0.3
PSW7 BIT  0xD0.7



?PR?EC1 SEGMENT ECODE 
?PR?C2 SEGMENT CODE
Public Reset, START, lab1, func1, func2

                CSEG    AT 0
                LJMP    Reset

                RSEG ?PR?C2
Reset:          ANL     AUXR1,#0xFE  ; DPTR[0]
                MOV     DPTR,#0x1234
                ORL     AUXR1,#0x01  ; DPTR[1]
                MOV     DPTR,#0xABCD

                ANL     AUXR1,#0xFE  ; DPTR[0]
                ORL     AUXR1,#0x01  ; DPTR[1]

                ORL     MXCON,#0x02  ; 16-Bit StackMode
                MOV     SP,#00
                MOV     SPE,#0x02 ; SPX:=E:0x200
START:
                ECALL   Func1
                EJMP    func2
lab1:           SJMP    start

RSEG ?PR?EC1
func1:          INC     EPTR
                ERET

func2:          ADD     PR1,#3
                EJMP    lab1

                END

