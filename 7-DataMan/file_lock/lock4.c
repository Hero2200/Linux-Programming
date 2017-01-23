/*
 * =====================================================================================
 *       Filename:  lock4.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月23日 20时29分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define NAME "/tmp/test_loc"
int main ( int argc, char *argv[] )
{
	int fd;
	struct flock reg;
	int len;
	if((fd = open(NAME,O_RDWR|O_CREAT,0666)) == -1){
		perror("open file error");
		exit(-1);
	}

	reg.l_type = F_WRLCK;
	reg.l_whence = SEEK_SET;
	reg.l_start = 10;
	reg.l_len = 50;
	if((fcntl(fd,F_SETLK,&reg)) == -1){
		perror("fcntl file error");
		exit(-1);
	}
	printf ( "fcntl SETLCK 10-60\n" );
	getchar();

	return 0;
}				
