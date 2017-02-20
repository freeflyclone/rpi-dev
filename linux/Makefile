DESTDIR=/tftpboot
TFTPBOOT=tftpboot
DTB=bcm2836-rpi-2-b.dtb
ZIMAGE=zImage
UINITRD=uInitrd

HAVE_KERNEL=$(shell ls kernel)

# setting cross compiler for the linux kernel
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-

# default build rules for the subdir makefile system.
include ../topheader.mk

ALL=$(TFTPBOOT).scr
DEPENDS=$(ZIMAGE) $(DTB) $(UINITRD)

EXTRA_CLEAN=@-rm -rf $(TFTPBOOT).scr $(ZIMAGE) $(DTB) $(UINITRD) ; (cd drivers ; make clean)


# the default targets
include $(TOPDIR)/topfooter.mk

$(TFTPBOOT).scr: $(TFTPBOOT).cmd
	mkimage -C none -A arm -T script -d $(TFTPBOOT).cmd $(TFTPBOOT).scr

$(ZIMAGE): kernel/arch/arm/boot/$(ZIMAGE)
	cp $< $@

$(DTB): kernel/arch/arm/boot/dts/$(DTB)
	cp $< $@

$(UINITRD): initramfs/uInitrd
	cp $< $@

kernel/arch/arm/boot/$(ZIMAGE):
ifeq ($(HAVE_KERNEL),)
	@echo Linux kernel source is not present, and it should be!
else
	@echo Found linux kernel...
	(cd kernel ; make bcm2835_defconfig ; make -j8 $(ZIMAGE) dtbs)
endif

distclean:
	(cd kernel ; make distclean)

install: $(TFTPBOOT).scr
	cp $(TFTPBOOT).scr $(DESTDIR)
	cp $(ZIMAGE) $(DESTDIR)
	cp $(DTB) $(DESTDIR)
	cp $(UINITRD) $(DESTDIR)

.PHONY: drivers

drivers:
	(cd drivers ; make)

