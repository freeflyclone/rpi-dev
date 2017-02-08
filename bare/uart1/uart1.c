//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

#define PERIPHERAL_BASE	0x3F000000

#define GPFSEL1 PERIPHERAL_BASE + 0x200004
#define GPSET0  PERIPHERAL_BASE + 0x20001C
#define GPCLR0  PERIPHERAL_BASE + 0x200028
#define GPPUD       PERIPHERAL_BASE + 0x200094
#define GPPUDCLK0   PERIPHERAL_BASE + 0x200098

#define AUX_ENABLES     PERIPHERAL_BASE + 0x215004
#define AUX_MU_IO_REG   PERIPHERAL_BASE + 0x215040
#define AUX_MU_IER_REG  PERIPHERAL_BASE + 0x215044
#define AUX_MU_IIR_REG  PERIPHERAL_BASE + 0x215048
#define AUX_MU_LCR_REG  PERIPHERAL_BASE + 0x21504C
#define AUX_MU_MCR_REG  PERIPHERAL_BASE + 0x215050
#define AUX_MU_LSR_REG  PERIPHERAL_BASE + 0x215054
#define AUX_MU_MSR_REG  PERIPHERAL_BASE + 0x215058
#define AUX_MU_SCRATCH  PERIPHERAL_BASE + 0x21505C
#define AUX_MU_CNTL_REG PERIPHERAL_BASE + 0x215060
#define AUX_MU_STAT_REG PERIPHERAL_BASE + 0x215064
#define AUX_MU_BAUD_REG PERIPHERAL_BASE + 0x215068

//GPIO14  TXD0 and TXD1
//GPIO15  RXD0 and RXD1
//alt function 5 for uart1
//alt function 0 for uart0

//((250,000,000/115200)/8)-1 = 270

int notmain ( void )
{
    unsigned int ra;

    PUT32(AUX_ENABLES,1);
    PUT32(AUX_MU_IER_REG,0);
    PUT32(AUX_MU_CNTL_REG,0);
    PUT32(AUX_MU_LCR_REG,3);
    PUT32(AUX_MU_MCR_REG,0);
    PUT32(AUX_MU_IER_REG,0);
    PUT32(AUX_MU_IIR_REG,0xC6);
    PUT32(AUX_MU_BAUD_REG,270);

    ra=GET32(GPFSEL1);
    ra&=~(7<<12); //gpio14
    ra|=2<<12;    //alt5
    PUT32(GPFSEL1,ra);

    PUT32(GPPUD,0);
    for(ra=0;ra<150;ra++) dummy(ra);
    PUT32(GPPUDCLK0,(1<<14));
    for(ra=0;ra<150;ra++) dummy(ra);
    PUT32(GPPUDCLK0,0);

    PUT32(AUX_MU_CNTL_REG,2);

    ra=0;
    while(1)
    {
        while(1)
        {
            if(GET32(AUX_MU_LSR_REG)&0x20) break;
        }
        PUT32(AUX_MU_IO_REG,0x30+(ra++&7));
    }

    return(0);
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
//
// Copyright (c) 2012 David Welch dwelch@dwelch.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------
