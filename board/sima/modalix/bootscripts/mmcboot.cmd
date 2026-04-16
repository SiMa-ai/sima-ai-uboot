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

nfs_linux_intf=$nfs_linux_intf
if test -n ${nfs_linux_intf}; then
	setenv nfs_linux_intf_cmd "nfs_linux_intf=${nfs_linux_intf}"
fi;

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
fdt addr ${fdt_addr}
setenv all_dtbos
if test -n "${dtbos}"; then setenv all_dtbos ${dtbos}; fi
if test -n "${secure_boot_dtbo}"; then setenv all_dtbos ${all_dtbos} ${secure_boot_dtbo}; fi
#Loop through provided dtbos and apply them
for dtbo in ${all_dtbos}; do
	# Skip if the variable happens to be empty
	if test -n "${dtbo}"; then
		fdt resize ${dtb_resize}
		fatload mmc ${devnum}:${distro_bootpart} ${dtbo_addr} ${boot_path}${dtbo}
		fdt apply ${dtbo_addr}
	fi
done
# Determine which Kernel Image to load based on the C-provided variable
if test "${secure_boot_mode}" = "1"; then
    echo "Secure Boot detected: Loading encrypted Image.enc"
    setenv kernel_file "Image.enc"
else
    echo "Standard Boot: Loading Image"
    setenv kernel_file "Image"
fi
fatload mmc ${devnum}:${distro_bootpart} $kernel_addr ${boot_path}${kernel_file};
test "$target_rootfs_" = "cpio" && fatload mmc ${devnum}:${distro_bootpart} $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
# Cleanup RAM variables before execution
# This ensures that even if booti fails or a user stops at the prompt,
# these temporary variables aren't sitting around to be accidentally saved.
setenv kernel_file
setenv secure_boot_mode
setenv secure_boot_dtbo
booti $kernel_addr $booti_initrd_ $fdt_addr
