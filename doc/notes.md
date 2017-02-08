### Notes

Stuff gathered here and there whilst trying to make progress.

Note: I use 0x0000,0000 to signify a 32-bit number/address in hex.  The comma is just a visual aid.

Using bootloader.bin/start.elf to load an image (without a config.txt) file:

    Pi 2/3 : kernel7.img
      Pi 1 : kernel.img

The bootloader.bin(start.elf?) jumps to 0x0000,8000, thus your kernel.img needs to target that address as it's entry point.

Peripheral base address:

        1 : 0x2000,0000
      2&3 : 0x3F00,0000
  
U-Boot loads at 0x0000,8000, to boot something with U-Boot requires that it be loaded to a different address. 

The default configuration for U-Boot for the rpi 3 (rpi_3_32b_defconfig) sets an environment variable *$loadaddr* to 0x0020,0000.  

A bare-metal program targeted to that address can be loaded via **tftp [file_name_on_server]**, this can be accomplished with an LD script. 
