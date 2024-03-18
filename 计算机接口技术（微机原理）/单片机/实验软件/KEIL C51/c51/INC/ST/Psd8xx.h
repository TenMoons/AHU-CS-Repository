/*--------------------------------------------------------------------------
PSD8xx.H

Header file for ST PSD8xx microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __PSD8xx_H__
#define __PSD8xx_H__

typedef xdata struct REG_8XX_st {
        uchar DATAIN_A;         // PSD_REG_BASE +0x00
        uchar DATAIN_B;         //              +0x01
        uchar CONTROL_A;        //              +0x02
        uchar CONTROL_B;        //              +0x03
        uchar DATAOUT_A;        //              +0x04
        uchar DATAOUT_B;        //              +0x05
        uchar DIRECTION_A;      //              +0x06
        uchar DIRECTION_B;      //              +0x07
        uchar DRIVE_A;          //              +0x08
        uchar DRIVE_B;          //              +0x09
        uchar IMC_A;            //              +0x0A
        uchar IMC_B;            //              +0x0B
        uchar OUTENABLE_A;      //              +0x0C
        uchar OUTENABLE_B;      //              +0x0D
        uchar res2[2];          //      spacer
        uchar DATAIN_C;         //              +0x10
        uchar DATAIN_D;         //              +0x11
        uchar DATAOUT_C;        //              +0x12 
        uchar DATAOUT_D;        //              +0x13
        uchar DIRECTION_C;      //              +0x14
        uchar DIRECTION_D;      //              +0x15
        uchar DRIVE_C;          //              +0x16
        uchar DRIVE_D;          //              +0x17
        uchar IMC_C;            //              +0x18
        uchar res1a;            //      spacer
        uchar OUTENABLE_C;      //              +0x1A
        uchar OUTENABLE_D;      //              +0x1B
        uchar res4[4];          //      spacer
        uchar OMC_AB;           //              +0x20
        uchar OMC_BC;           //              +0x21
        uchar OMCMASK_AB;       //              +0x22
        uchar OMCMASK_BC;       //              +0x23
        uchar res8c[0x8C];      //      spacer
        uchar PMMR0;            //              +0xB0
        uchar res1b;            //      spacer
        uchar PMMR1;            //              +0xB2
        uchar res1c;            //      spacer
        uchar PMMR2;            //              +0xB4
        uchar res0B[0x0B];      //      spacer
        uchar MAINPROTECT;      //              +0xC0
        uchar res1d;            //      spacer
        uchar ALTPROTECT;       //              +0xC2
        uchar res4a[4];          //      spacer
        uchar JTAG;             //              +0xC7
        uchar res18[0x18];      //      spacer
        uchar PAGE;             //              +0xE0
        uchar res1e;            //      spacer
        uchar VM;               //              +0xE2
	uchar res29[0x1d];	//    	spacer
} REG_8XX;



#endif

