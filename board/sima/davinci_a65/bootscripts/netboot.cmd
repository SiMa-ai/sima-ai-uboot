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
test -n "$netcfg" || netcfg=static;
test -n "$target_rootfs" || target_rootfs_=cpio; fix_cmd=fix_rootfs_${target_rootfs_}; run $fix_cmd;
tftp $fdt_addr $fdt_name; tftp $kernel_addr Image;
test "$target_rootfs_" = "cpio" && tftp $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
booti $kernel_addr $booti_initrd_ $fdt_addr
