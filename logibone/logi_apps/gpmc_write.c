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
	int fd, address ,numbers,value;
	unsigned short i ,j;
	unsigned short *writeVal ;
	if(argc  < 3){
		printf("not enough arguments \n");
		printf("%s address value2write nuber2write\n",argv[0]);
		return 0 ;
	}
	address = (int) strtol(argv[1], NULL, 0);
	value   = (unsigned short) strtol(argv[2], NULL, 0);
	numbers = (int) strtol(argv[3], NULL, 0);
	writeVal=(unsigned short *)calloc(numbers,sizeof(unsigned short)*2);
	if(writeVal==NULL){
		printf("Error calloc()\n");
		return 0 ;
	}
	for(i = 0,j=0; i < numbers*2; i+=2,j++){
		*(writeVal+i)=value+j;
		*(writeVal+i+1)=value+j;
	}
	fd = open("/dev/logibone_mem", O_RDWR | O_SYNC);
	if(pwrite(fd, writeVal, numbers*2, address) < numbers*2){
		printf("Write error !");
	}
	close(fd);

	printf("Writing %d words @ 0x%x \n", numbers, address);
	free(writeVal);;
	return 0 ;
}
