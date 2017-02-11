tftp ${kernel_addr_r} zImage
tftp ${ramdisk_addr_r} uInitrd
tftp ${fdt_addr_r} bcm2836-rpi-2-b.dtb 
setenv bootargs console=ttyAMA0,115200 earlyprintk root=/dev/root rootwait panic=10
bootz ${kernel_addr_r} ${ramdisk_addr_r} ${fdt_addr_r}
