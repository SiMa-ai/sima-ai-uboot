# This is an example file to generate usbboot.scr.uimg - a boot script for U-Boot
# This example only target for usb boot.
# Generate usbboot.scr.uimg:
# ./tools/mkimage -c none -A arm -T script -d usbboot.cmd usbboot.scr.uimg
#
# It requires a list of environment variables used below to be defined
# before load
#

target_rootfs_=$target_rootfs
booti_initrd_=$booti_initrd
overlay_dir=overlays

test -n "$target_rootfs" || target_rootfs_=cpio; fix_cmd=fix_rootfs_${target_rootfs_}; run $fix_cmd;

fatload usb ${usbdev}:${usbpart} $fdt_addr $fdt_name;
fdt addr ${fdt_addr}
#Loop through provided dtbos and apply them
for dtbo in ${dtbos}; do
	fdt resize ${dtb_resize}
	fatload usb ${usbdev}:${usbpart} ${dtbo_addr} ${overlay_dir}/${dtbo}
	fdt apply ${dtbo_addr}
done

fatload usb ${usbdev}:${usbpart} $kernel_addr Image;
test "$target_rootfs_" = "cpio" &&  fatload usb ${usbdev}:${usbpart} $cpio_addr $cpio_name && booti_initrd_=$cpio_addr:$cpio_size;
booti $kernel_addr $booti_initrd_ $fdt_addr
