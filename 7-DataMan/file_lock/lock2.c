#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ( int argc, char *argv[] )
{
	int fd,i=10;
	while(i--){
		fd= open("/tmp/LCK.test2",O_RDWR|O_CREAT|O_EXCL,0666);
		if(fd == -1){
			perror("LOCK open file error:");
			sleep(2);
		}else{
			printf ( "open ok\n" );
			sleep(1);
			close(fd);
			unlink("/tmp/LCK.test2");
			sleep(2);
		}
	}
	return 0;
}				
