July 20, 2016

This package includes following file-tree
	logi_patch\
	app_logibone\
	uEnv.txt

1.	Go to your openwrt directory
Copy uEnv.txt to there
copy app_logibone to feeds\packges\utils\

2.	Patch files(logi_patch\) to Linux kernel
Kernel source is under 
./ build_dir/target-arm_cortex-a9+vfpv3_uClibc-0.9.33.2_eabi/linux-omap/linux-3.18.27/. 

3.	Do a make kernel_menuconfig in the openwrt dir and enable
		 "Device drivers" -> "SPI" :
				McSPI driver for OMAP
				User mode SPI device
		"Device drivers" -> "MISC"
		 - Beaglebone Logibone cape

4.	The compile OpenWRT as usual “make -j1 V=s”.



