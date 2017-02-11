OUTPUTFILE=linux

#specify the bare-metal cross compiler
CROSS_COMPILE=arm-linux-gnueabihf-

# default build rules for the subdir makefile system.
include ../topheader.mk

ALL=itb
EXTRA_CLEAN=@-rm -rf $(OUTPUTFILE).itb

# the default targets
include $(TOPDIR)/topfooter.mk

# make an FIT image for U-Boot
itb:
	mkimage -f $(OUTPUTFILE).its $(OUTPUTFILE).itb
