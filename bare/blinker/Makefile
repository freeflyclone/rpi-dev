PROGRAM=blinker

CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-

CFLAGS+=-nostdlib -nostartfiles -ffreestanding
LDFLAGS +=-Tblinker.ld

include ../../topheader.mk

DEPENDS=image
PROGRAM_SOURCES += bootstrap.s $(PROGRAM).c

include $(TOPDIR)/topfooter.mk

image: binary
	mkimage -a 0x8000 -e 0x8000 -C none -A arm -T standalone -d $(PROGRAM).bin $(PROGRAM).img

binary: $(PROGRAM)
	$(OBJCOPY) $(PROGRAM) -O binary $(PROGRAM).bin

strip:
	$(STRIP) $(PROGRAM)

install:
	cp $(PROGRAM) /tftpboot/$(PROGRAM).elf
