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
part list mmc ${devnum} -bootable bparts; for bpart in ${bparts}; do if test ${bpart} -eq 5; then;env set rootfs_partid 5;elif test ${bpart} -eq 4;then; env set rootfs_partid 4;fi; done;
if test ${upgrade_available} -eq 1; then
	if test -n ${bootcount} && test ${bootcount} -gt ${bootlimit}; then
		echo "failed to boot from current version, fall back to previous"
		if test ${rootfs_partid} -eq 5; then
                	setenv rootfs_partid 4
                else
                	setenv rootfs_partid 5
                fi
                setenv upgrade_available 0;setenv bootcount 0;setenv fallback true;saveenv
fi;fi;
test -n "$target_rootfs" || target_rootfs_=mmc; fix_cmd=fix_rootfs_${target_rootfs_}; run $fix_cmd;
fatload mmc ${devnum}:${distro_bootpart} $fdt_addr ${boot_path}$fdt_name;
fatload mmc ${devnum}:${distro_bootpart} $kernel_addr ${boot_path}Image;
test "$target_rootfs_" = "cpio" && fatload mmc ${devnum}:${distro_bootpart} $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
booti $kernel_addr $booti_initrd_ $fdt_addr
