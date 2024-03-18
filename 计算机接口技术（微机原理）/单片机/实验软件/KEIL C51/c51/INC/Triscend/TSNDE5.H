// Example header file only.  Do not use in a real design.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  -------------------------------------------------------------------------------------------
//  ------------------  IMPORTANT DISCLAIMER PLEASE READ   --------------------
//  -------------------------------------------------------------------------------------------
//  This header file is produced to serve as an example only.  It contains no CSL configuration
//  information and will not work for any actual design.   Before you complete your  
//  CSoC design, you should use FastChip to generate a header file and use generated header  
//  file in your application.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//======== Required symbol and macro definitions ========

#ifdef PROTOTYPE_ONLY
#   define CHAR_XDATA(name,location) extern volatile unsigned char xdata name;
#   define CHAR_ARRAY_XDATA(name,location,size) extern volatile unsigned char xdata name[size];
#else
#   define CHAR_XDATA(name,location) volatile unsigned char xdata name _at_ location;
#   define CHAR_ARRAY_XDATA(name,location,size) volatile unsigned char xdata name[size] _at_ location;
#endif

//========= BEGIN SOFT MODULE REGISTER DECLARATIONS ======

//========== END SOFT MODULE REGISTER DECLARATIONS =======

//======== E5 byte addressable SFR registers ========
    // -- reserved (P0) --
    sfr     SP      =   0x81;
    sfr     DPL     =   0x82;
    sfr     DPH     =   0x83;
    sfr     DPL1    =   0x84;
    sfr     DPH1    =   0x85;
    sfr     DPS     =   0x86;
    sfr     PCON    =   0x87;
    sfr     TCON    =   0x88;
    sfr     TMOD    =   0x89;
    sfr     TL0     =   0x8a;
    sfr     TL1     =   0x8b;
    sfr     TH0     =   0x8c;
    sfr     TH1     =   0x8d;
    sfr     CKCON   =   0x8e;
    // -- reserved (P1) --
    sfr     SCON    =   0x98;
    sfr     SBUF    =   0x99;
    // -- reserved (P2) --
    sfr     IE      =   0xa8;
    sfr     SADDR   =   0xa9;
    // -- reserved (P3) --
    sfr     IP      =   0xb8;
    sfr     SADEN   =   0xb9;
    sfr     TA      =   0xc7;
    sfr     T2CON   =   0xc8;
    sfr     T2MOD   =   0xc9;
    sfr     RCAP2L  =   0xca;
    sfr     RCAP2H  =   0xcb;
    sfr     TL2     =   0xcc;
    sfr     TH2     =   0xcd;
    sfr     PSW     =   0xd0;
    sfr     WDCON   =   0xd8;
    sfr     ACC     =   0xe0;
    sfr     EIE     =   0xe8;
    sfr     B       =   0xf0;
    sfr     EIP     =   0xf8;

//======== E5 bit addressable SFR registers ========
//---------------------------- TCON
    sbit    TF1     =   0x8f;
    sbit    TR1     =   0x8e;
    sbit    TF0     =   0x8d;
    sbit    TR0     =   0x8c;
    sbit    IE1     =   0x8b;
    sbit    IT1     =   0x8a;
    sbit    IE0     =   0x89;
    sbit    IT0     =   0x88;
//---------------------------- SCON
    sbit    SM0     =   0x9f;
    sbit    SM1     =   0x9e;
    sbit    SM2     =   0x9d;
    sbit    REN     =   0x9c;
    sbit    TB8     =   0x9b;
    sbit    RB8     =   0x9a;
    sbit    TI      =   0x99;
    sbit    RI      =   0x98;
//---------------------------- IE
    sbit    EA      =   0xaf;
    // -- reserved --
    sbit    ET2     =   0xad;
    sbit    ES      =   0xac;
    sbit    ET1     =   0xab;
    sbit    EX1     =   0xaa;
    sbit    ET0     =   0xa9;
    sbit    EX0     =   0xa8;
//---------------------------- IP
    // -- reserved --
    // -- reserved --
    sbit    PT2     =   0xbd;
    sbit    PS      =   0xbc;
    sbit    PT1     =   0xbb;
    sbit    PX1     =   0xba;
    sbit    PT0     =   0xb9;
    sbit    PX0     =   0xb8;
//---------------------------- T2CON
    sbit    TF2     =   0xcf;
    sbit    EXF2    =   0xce;
    sbit    RCLK    =   0xcd;
    sbit    TCLK    =   0xcc;
    sbit    EXEN2   =   0xcb;
    sbit    TR2     =   0xca;
    sbit    C_T2    =   0xc9;
    sbit    CP_RL2  =   0xc8;
//---------------------------- PSW
    sbit    CY      =   0xd7;
    sbit    AC      =   0xd6;
    sbit    F0      =   0xd5;
    sbit    RS1     =   0xd4;
    sbit    RS0     =   0xd3;
    sbit    OV      =   0xd2;
    // -- reserved --
    sbit    P       =   0xd0;
//---------------------------- WDCON
    // -- reserved --
    sbit    POR     =   0xde;
    sbit    EHPI    =   0xdd;
    sbit    HPI     =   0xdc;
    sbit    WDIF    =   0xdb;
    sbit    WTRF    =   0xda;
    sbit    EWT     =   0xd9;
    sbit    RWT     =   0xd8;
//---------------------------- EIE
    // -- reserved --
    // -- reserved --
    // -- reserved --
    sbit    EWDI    =   0xec;
    // -- reserved --
    // -- reserved --
    // -- reserved --
    // -- reserved --
//---------------------------- EIP
    // -- reserved --
    // -- reserved --
    // -- reserved --
    sbit    PWDI    =   0xfc;
    // -- reserved --
    // -- reserved --
    // -- reserved --
    // -- reserved --


//========= Visible CRU Registers ========
#define E5CRU_VISIBLE_BASE_ADDR 0xf000
    CHAR_XDATA ( CMAP0_TAR,        0xff00 )
    CHAR_XDATA ( CMAP0_ALT,        0xff01 )
    CHAR_XDATA ( CMAP1_TAR_0,      0xff02 )
    CHAR_XDATA ( CMAP1_TAR_1,      0xff03 )
    CHAR_XDATA ( CMAP1_TAR_2,      0xff04 )
    CHAR_XDATA ( CMAP1_SRC,        0xff05 )
    CHAR_XDATA ( CMAP1_CTL,        0xff06 )
    CHAR_XDATA ( CMAP1_ALT,        0xff07 )
    CHAR_XDATA ( CMAP2_TAR_0,      0xff08 )
    CHAR_XDATA ( CMAP2_TAR_1,      0xff09 )
    CHAR_XDATA ( CMAP2_TAR_2,      0xff0a )
    CHAR_XDATA ( CMAP2_SRC,        0xff0b )
    CHAR_XDATA ( CMAP2_CTL,        0xff0c )
    CHAR_XDATA ( CMAP2_ALT,        0xff0d )
    CHAR_XDATA ( DMAP0_TAR,        0xff0e )
    CHAR_XDATA ( DMAP1_TAR_0,      0xff0f )
    CHAR_XDATA ( DMAP1_TAR_1,      0xff10 )
    CHAR_XDATA ( DMAP1_TAR_2,      0xff11 )
    CHAR_XDATA ( DMAP1_SRC,        0xff12 )
    CHAR_XDATA ( DMAP1_CTL,        0xff13 )
    CHAR_XDATA ( DMAP2_TAR_0,      0xff14 )
    CHAR_XDATA ( DMAP2_TAR_1,      0xff15 )
    CHAR_XDATA ( DMAP2_TAR_2,      0xff16 )
    CHAR_XDATA ( DMAP2_SRC,        0xff17 )
    CHAR_XDATA ( DMAP2_CTL,        0xff18 )
    CHAR_XDATA ( DMAP3_TAR,        0xff19 )
    CHAR_XDATA ( DMAP3_SRC,        0xff1a )
    CHAR_XDATA ( DMAP3_CTL,        0xff1b )
    // -- reserved --
    // -- reserved --
    // -- reserved --
    // -- reserved --
    CHAR_XDATA ( DMASADR0_0,       0xff20 )
    CHAR_XDATA ( DMASADR0_1,       0xff21 )
    CHAR_XDATA ( DMASADR0_2,       0xff22 )
    CHAR_XDATA ( DMASADR0_3,       0xff23 )
    CHAR_XDATA ( DMASCNT0_0,       0xff24 )
    CHAR_XDATA ( DMASCNT0_1,       0xff25 )
    CHAR_XDATA ( DMASCNT0_2,       0xff26 )
    CHAR_XDATA ( DMACTRL0_0,       0xff27 )
    CHAR_XDATA ( DMACTRL0_1,       0xff28 )
    CHAR_XDATA ( DMAEINT0,         0xff29 )
    CHAR_XDATA ( DMAINT0,          0xff2a )
    CHAR_XDATA ( DMACADR0_0,       0xff2b )
    CHAR_XDATA ( DMACADR0_1,       0xff2c )
    CHAR_XDATA ( DMACADR0_2,       0xff2d )
    CHAR_XDATA ( DMACADR0_3,       0xff2e )
    CHAR_XDATA ( DMACCNT0_0,       0xff2f )
    CHAR_XDATA ( DMACCNT0_1,       0xff30 )
    CHAR_XDATA ( DMACCNT0_2,       0xff31 )
    CHAR_XDATA ( DMAPREQ0_0,       0xff32 )
    CHAR_XDATA ( DMAPREQ0_1,       0xff33 )
    CHAR_XDATA ( DMASADR1_0,       0xff34 )
    CHAR_XDATA ( DMASADR1_1,       0xff35 )
    CHAR_XDATA ( DMASADR1_2,       0xff36 )
    CHAR_XDATA ( DMASADR1_3,       0xff37 )
    CHAR_XDATA ( DMASCNT1_0,       0xff38 )
    CHAR_XDATA ( DMASCNT1_1,       0xff39 )
    CHAR_XDATA ( DMASCNT1_2,       0xff3a )
    CHAR_XDATA ( DMACTRL1_0,       0xff3b )
    CHAR_XDATA ( DMACTRL1_1,       0xff3c )
    CHAR_XDATA ( DMAEINT1,         0xff3d )
    CHAR_XDATA ( DMAINT1,          0xff3e )
    CHAR_XDATA ( DMACADR1_0,       0xff3f )
    CHAR_XDATA ( DMACADR1_1,       0xff40 )
    CHAR_XDATA ( DMACADR1_2,       0xff41 )
    CHAR_XDATA ( DMACADR1_3,       0xff42 )
    CHAR_XDATA ( DMACCNT1_0,       0xff43 )
    CHAR_XDATA ( DMACCNT1_1,       0xff44 )
    CHAR_XDATA ( DMACCNT1_2,       0xff45 )
    CHAR_XDATA ( DMAPREQ1_0,       0xff46 )
    CHAR_XDATA ( DMAPREQ1_1,       0xff47 )
    CHAR_XDATA ( DMACRC_0,         0xff48 )
    CHAR_XDATA ( DMACRC_1,         0xff49 )

    CHAR_XDATA ( PROTECT,          0xff60 )
    CHAR_XDATA ( SECURITY,         0xff61 )
    CHAR_XDATA ( PWDSEL,           0xff62 )
    CHAR_XDATA ( PORCTRL,          0xff63 )

    CHAR_XDATA ( DMAP4_TAR_0,      0xff80 )
    CHAR_XDATA ( DMAP4_TAR_1,      0xff81 )
    CHAR_XDATA ( DMAP4_TAR_2,      0xff82 )
    CHAR_XDATA ( DMAP4_SRC,        0xff83 )
    CHAR_XDATA ( DMAP4_CTL,        0xff84 )
    CHAR_XDATA ( DMAP5_TAR_0,      0xff85 )
    CHAR_XDATA ( DMAP5_TAR_1,      0xff86 )
    CHAR_XDATA ( DMAP5_TAR_2,      0xff87 )
    CHAR_XDATA ( DMAP5_SRC,        0xff88 )
    CHAR_XDATA ( DMAP5_CTL,        0xff89 )

