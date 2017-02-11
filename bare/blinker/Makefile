PROGRAM=blinker

#specify the bare-metal cross compiler
CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-

#tell the compiler not to add extra OS-related stuff
CFLAGS+=-nostdlib -nostartfiles -ffreestanding

#use a linker script to specify exactly where the binary should live in RAM on the target.
#(although I'm not sure it matters, position independent code seems to be the default)
LDFLAGS +=-Tblinker.ld

# we make extra intermediate binary thingies, so clean those up as well when "make clean"
EXTRA_CLEAN=@-rm -rf $(PROGRAM).itb $(PROGRAM).bin

# default build rules for the subdir makefile system.
include ../../topheader.mk

#the default all: target now depends on the local uimage: target
DEPENDS=uimage

# the list of sources to make $(PROGRAM)
PROGRAM_SOURCES += bootstrap.s $(PROGRAM).c

# the default targets
include $(TOPDIR)/topfooter.mk

# make an FIT image for U-Boot
uimage: binary
	mkimage -f $(PROGRAM).its $(PROGRAM).itb

# extract just the code portiong from the ELF format file produced by the compiler
binary: $(PROGRAM)
	$(OBJCOPY) $(PROGRAM) -O binary $(PROGRAM).bin
