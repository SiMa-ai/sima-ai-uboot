# This is an example file to generate netboot.scr.uimg - a boot script for U-Boot
# This example only target for net boot.
# Generate netboot.scr.uimg:
# ./tools/mkimage -c none -A arm -T script -d netboot.cmd netboot.scr.uimg
#
# It requires a list of environment variables used below to be defined
# before load
#

target_rootfs_=$target_rootfs
booti_initrd_=$booti_initrd
netcfg=$forcenetcfg
overlay_dir=overlays
test -n "$netcfg" || netcfg=static;

nfs_linux_intf=$nfs_linux_intf
if test -n ${nfs_linux_intf}; then
	setenv nfs_linux_intf_cmd "nfs_linux_intf=${nfs_linux_intf}"
fi;

test -n "$target_rootfs" || target_rootfs_=cpio; fix_cmd=fix_rootfs_${target_rootfs_}; run $fix_cmd;

tftp $fdt_addr $fdt_name;
fdt addr ${fdt_addr}
#Loop through provided dtbos and apply them
for dtbo in ${dtbos}; do
	fdt resize ${dtb_resize}
	tftp ${dtbo_addr} ${overlay_dir}/${dtbo}
	fdt apply ${dtbo_addr}
done

tftp $kernel_addr Image;
test "$target_rootfs_" = "cpio" && tftp $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
booti $kernel_addr $booti_initrd_ $fdt_addr
