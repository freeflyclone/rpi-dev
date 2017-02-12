OUTPUTFILE=linux
TFTPBOOT=tftpboot

# default build rules for the subdir makefile system.
include ../topheader.mk

ALL=$(TFTPBOOT).scr

EXTRA_CLEAN=@-rm -rf $(OUTPUTFILE).itb $(TFTPBOOT).scr

# the default targets
include $(TOPDIR)/topfooter.mk

$(TFTPBOOT).scr: $(TFTPBOOT).cmd
	mkimage -C none -A arm -T script -d $(TFTPBOOT).cmd $(TFTPBOOT).scr
	cp $@ /tftpboot
