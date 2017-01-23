#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ( int argc, char *argv[] )
{
	int fd;
	fd= open("/tmp/LCK.test",O_RDWR|O_CREAT|O_EXCL,0666);
	if(fd == -1){
		perror("open file error");
		exit(-1);
	}

	printf ( "open ok\n" );
	close(fd);
	return 0;
}				
