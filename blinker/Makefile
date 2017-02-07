PROGRAM=blinker

CFLAGS+=-nostdlib -nostartfiles -ffreestanding
CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-
LDFLAGS +=-Ttext 0x00008000

include ../topheader.mk

PROGRAM_SOURCES += bootstrap.s $(PROGRAM).c

include $(TOPDIR)/topfooter.mk

strip:
	$(STRIP) $(PROGRAM)

install:
	cp $(PROGRAM) /tftpboot/$(PROGRAM).elf
