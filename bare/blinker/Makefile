PROGRAM=blinker

CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-

CFLAGS+=-nostdlib -nostartfiles -ffreestanding
LDFLAGS +=-Tblinker.ld
EXTRA_CLEAN=@-rm -rf $(PROGRAM).itb $(PROGRAM).bin

include ../../topheader.mk

#the default all: target now depends on the local uimage: target
DEPENDS=uimage

PROGRAM_SOURCES += bootstrap.s $(PROGRAM).c

include $(TOPDIR)/topfooter.mk

uimage: binary
	mkimage -f $(PROGRAM).its $(PROGRAM).itb

binary: $(PROGRAM)
	$(OBJCOPY) $(PROGRAM) -O binary $(PROGRAM).bin

strip:
	$(STRIP) $(PROGRAM)
