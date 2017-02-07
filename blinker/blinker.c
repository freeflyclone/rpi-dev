//#define PERIPHERAL_BASE 0x20000000 // for rpi 1

#define PERIPHERAL_BASE 0x3F000000 // for rpi 2&3

enum Gpio {
	GPFSEL0=PERIPHERAL_BASE + 0x200000,
	GPFSEL1,
	GPFSEL2,
	GPFSEL3,
	GPFSEL4,
	GPFSEL5
};

int apple=0;

int notmain(int argc, char *argv[]) {
	volatile int a = 0;

	apple += 7;

	while(1)
		a++;
		
	return 0;
}

void _exit(int x) {
	while(1);
}
