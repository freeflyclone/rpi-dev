PROGRAM=uart1

CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-

CFLAGS+=-nostdlib -nostartfiles -ffreestanding
LDFLAGS +=-T$(PROGRAM).ld

include ../../topheader.mk

PROGRAM_SOURCES += bootstrap.s $(PROGRAM).c

include $(TOPDIR)/topfooter.mk

binary: $(PROGRAM)
	$(OBJCOPY) $(PROGRAM) -O binary $(PROGRAM).bin

strip:
	$(STRIP) $(PROGRAM)

install:
	cp $(PROGRAM) /tftpboot/$(PROGRAM).elf
