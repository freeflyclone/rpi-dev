/* the following are defined in bootstrap.s */
extern void PUT32(unsigned int, unsigned int);
extern unsigned int GET32(unsigned int);
extern void dummy(unsigned int);

#define	GPFSEL1	0x3F200004
#define GPSET0	0x3F20001C
#define GPCLR0	0x3F200028

int notmain(int argc, char *argv[]) {
	unsigned int ra;

	ra = GET32(GPFSEL1);
	ra &= ~(7<<18);
	ra |= 1<<18;
	PUT32(GPFSEL1, ra);

	while (1) {
        PUT32(GPSET0,1<<16);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
        PUT32(GPCLR0,1<<16);
        for(ra=0;ra<0x100000;ra++) dummy(ra);
	}
	return 0;
}

void _exit(int x) {
	while(1);
}
