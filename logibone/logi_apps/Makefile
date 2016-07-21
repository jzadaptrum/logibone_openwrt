
CC=$(STAGING_DIR)/toolchain-arm_cortex-a9+vfpv3_gcc-4.8-linaro_uClibc-0.9.33.2_eabi/bin/arm-openwrt-linux-gcc

all: gpmc_read gpmc_write

clean:
	rm -f *.a *.o gpmc_read gpmc_write

gpmc_read : gpmc_read.c
	$(CC) -o $@ gpmc_read.c

gpmc_write : gpmc_write.c
	$(CC) -o $@ gpmc_write.c


