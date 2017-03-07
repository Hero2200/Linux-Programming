#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define file "/tmp/test_lockf"
int main ( int argc, char *argv[] )
{
	int fd,ret;
	char buf[100];
	memset(buf,'A',100);

	if((fd = open(file,O_RDWR|O_CREAT,0666)) == -1){
		perror("open file error");
		exit(-1);
	}
	write(fd,buf,100);
	ret = lockf(fd,F_LOCK,50);
	if(ret == -1){
		printf ( "lockf file fail\n" );
	}
	printf ( "lockf1 ok\n" );

	
/* 	ret = lockf(fd,F_LOCK,50);
 * 	if(ret == -1){
 * 		printf ( "lock2 file fail\n" );
 * 	}
 * 	printf ( "lockf2 ok\n" );
 */
	getchar();
	return 0;
}
