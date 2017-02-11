OUTPUTFILE=linux
TFTPBOOT=tftpboot

#specify the bare-metal cross compiler
CROSS_COMPILE=arm-linux-gnueabihf-

# default build rules for the subdir makefile system.
include ../topheader.mk

ALL=$(TFTPBOOT).scr

EXTRA_CLEAN=@-rm -rf $(OUTPUTFILE).itb $(TFTPBOOT).scr

# the default targets
include $(TOPDIR)/topfooter.mk

$(TFTPBOOT).scr:
	mkimage -C none -A arm -T script -d $(TFTPBOOT).cmd $(TFTPBOOT).scr

# make an FIT image for U-Boot
itb:
	mkimage -f $(OUTPUTFILE).its $(OUTPUTFILE).itb
