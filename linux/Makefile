OUTPUTFILE=linux

#specify the bare-metal cross compiler
CROSS_COMPILE=arm-linux-gnueabihf-

# default build rules for the subdir makefile system.
include ../topheader.mk

ALL=itb

# the default targets
include $(TOPDIR)/topfooter.mk

# make an FIT image for U-Boot
itb: uimage
	mkimage -f $(OUTPUTFILE).its $(OUTPUTFILE).itb

uimage: kernel.uimage fdt.uimage

kernel.uimage:
	mkimage -A arm -O linux -T kernel -C none -a 0x01000000 -e 0x01000000 -n "Linux kernel" -d kernel/arch/arm/boot/zImage kernel.uimage

fdt.uimage:
	mkimage -A arm -O linux -C none -a 0x100 -d kernel/arch/arm/boot/dts/bcm2836-rpi-2-b.dtb fdt.uimage
