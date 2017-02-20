tftp ${kernel_addr_r} zImage
tftp ${ramdisk_addr_r} uInitrd
tftp ${fdt_addr_r} bcm2836-rpi-2-b.dtb 
#
setenv ipaddr dhcp
setenv serverip 10.1.1.1
setenv bootargs console=ttyAMA0,115200 earlyprintk root=/dev/root rootwait panic=10 ip=${ipaddr}:${serverip}::255.255.255.0:rpi:eth0::8.8.4.4:8.8.8.8
#
bootz ${kernel_addr_r} ${ramdisk_addr_r} ${fdt_addr_r}
