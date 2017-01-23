/*
 * =====================================================================================
 *       Filename:  memory1.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 21时49分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ( int argc, char *argv[] )
{
	char *tmp=NULL;
	tmp = (char *)malloc(1024);
	if(tmp ==NULL){
		perror("malloc error ");
		exit(-1) ;
	}
//	snprintf(tmp,1024,"Hello world\n");
	char buf[]="Hellow world\n";
	memcpy(tmp,buf,strlen(buf));
	printf ( "%s\n",tmp );

	return 0;
}				
