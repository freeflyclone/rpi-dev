PROGRAM=blinker

CROSS_COMPILE=/opt/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-
include ../topheader.mk

PROGRAM_SOURCES += $(PROGRAM).cpp 

include $(TOPDIR)/topfooter.mk

strip:
	$(STRIP) $(PROGRAM)

install:
	cp $(PROGRAM) /tftpboot/$(PROGRAM).elf
