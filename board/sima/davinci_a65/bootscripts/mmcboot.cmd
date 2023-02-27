# This is an example file to generate boot.scr.uimg - a boot script for U-Boot
# This example only target for boot from vfat partition of eMMC or SD Card.
# Generate boot.scr.uimg:
# ./tools/mkimage -c none -A arm -T script -d mmcboot.cmd boot.scr.uimg
#
# It requires a list of environment variables used below to be defined
# before load
#

target_rootfs_=$target_rootfs
booti_initrd_=$booti_initrd
netcfg=$forcenetcfg
test -n "$netcfg" || netcfg=dhcp;
part list mmc ${devnum} -bootable bparts; for bpart in ${bparts}; do test ${bpart} -eq 5 && env set rootfs_partid 5; done;
test -n "$target_rootfs" || target_rootfs_=mmc; fix_cmd=fix_rootfs_${target_rootfs_}; run $fix_cmd;
fatload mmc ${devnum}:${distro_bootpart} $fdt_addr $fdt_name;
fatload mmc ${devnum}:${distro_bootpart} $kernel_addr Image;
test "$target_rootfs_" = "cpio" && fatload mmc ${devnum}:${distro_bootpart} $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
booti $kernel_addr $booti_initrd_ $fdt_addr
