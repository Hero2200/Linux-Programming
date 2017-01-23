/*
 * =====================================================================================
 *       Filename:  lock3.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 22时40分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

const char *file="/tmp/test_loc";
int main ( int argc, char *argv[] )
{
	int fd;
	char buf[100];
	struct flock reg_1;
	struct flock reg_2;
	memset(buf,'A',100);
	printf ( "%s\n",buf );
	fd=open(file,O_RDWR|O_CREAT,0666);
	if(fd==-1){
		perror("open error");
	}
	write(fd,buf,100);

	//1
	reg_1.l_type=F_WRLCK;
	reg_1.l_whence=SEEK_SET;
	reg_1.l_start=10;
	reg_1.l_len=20;
	printf ( "RDLCK file 10-30\n" );
	if((fcntl(fd,F_SETLK,&reg_1)) == -1){
		perror("LCK file error");
	}

	reg_2.l_type=F_WRLCK;
	reg_2.l_whence=SEEK_SET;
	reg_2.l_start=10;
	reg_2.l_len=30;
	if((fcntl(fd,F_SETLK,&reg_2)) == -1){
		perror("LCK2 file error");
	}

//	fcntl(fd,F_GETLK,&reg_2);
	sleep(5);
	lseek(fd,10,SEEK_SET);
	write(fd,"123456",6);
	getchar();
	return 0;
}				
