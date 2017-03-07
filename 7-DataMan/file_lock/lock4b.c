/*
 * =====================================================================================
 *       Filename:  lock4b.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月23日 21时38分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char *file="/tmp/test_loc";
int main ( int argc, char *argv[] )
{
	int fd;
	struct flock reg;
	if((fd = open(file,O_RDWR|O_CREAT,0666)) == -1){
		perror("open file error");
		exit(-1);
	}
	int i;
	for(i=0;i<100;i+=10){
		reg.l_type=F_RDLCK;
		reg.l_whence=SEEK_SET;
		reg.l_start=i;
		reg.l_len=10;
		if((fcntl(fd,F_SETLK,&reg)) == -1){
			perror("fcntl error");
			printf ( "fail %d %d\n",i,i+10 );
		}

		printf ( "ok %d-%d\n",i,i+10 );
	}
	return 0;
}
