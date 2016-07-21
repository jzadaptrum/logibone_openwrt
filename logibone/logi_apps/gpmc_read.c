#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
//#include <linux/ioctl.h>
#include <sys/ioctl.h>


int main(int argc, char ** argv){
	int fd, address ,numbers;
	unsigned short i ;
	unsigned short *readVal ;
	if(argc  < 2){
		printf("not enough arguments \n");
		printf("%s address nuber2read\n",argv[0]);
		return 0 ;
	}
	
	address = (int) strtol(argv[1], NULL, 0);
	numbers = (int) strtol(argv[2], NULL, 0);
	readVal = (unsigned short *)calloc(numbers,sizeof(unsigned short)*2);
	if(readVal==NULL){
		printf("Error calloc()\n");
		return 0 ;
	}

	fd = open("/dev/logibone_mem", O_RDWR | O_SYNC);
	pread(fd, readVal, numbers*2, address);
	close(fd);
	
	while(numbers-->0)	{
		printf("read 0x%x @ 0x%x \n", *readVal++, address);
		*readVal++;
		address+=4;
	}
	printf("\n");
	free(readVal);
	return 0 ;
}
