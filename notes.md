### Notes
Stuff gathered here and there whilst trying to make progress.

Pi 2/3 need to be kernel7.img

Pi 1 needs to be kernel.img

The bootloader.bin jumps to 0x8000, thus your kernel.img needs to target that address as it's entry point.

Peripheral base address:
	1 : 0x2000 0000
  2&3 :	0x3F00 0000
  
U-Boot loads at 0x8000, to boot something with U-Boot requires that it be loaded to a different address.  More on this when it has been discovered.
