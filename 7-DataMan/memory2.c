/*
 * =====================================================================================
 *       Filename:  memory2.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 21时57分19秒
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

#define MAX 1024
#define MEM (1024*1024)
int main ( int argc, char *argv[] )
{
	char *tmp;
	int i;
	char buf[]="Hellow world";
	int len=strlen(buf);
	while(i<MAX){
		tmp = (char *)malloc(MEM);
		if(tmp == NULL){
			perror("malloc error");
		}
		memcpy(tmp,buf,len);
//		printf ( "%d %s\n",i++,tmp );
		i++; //if no i++, mem all used ,arch no reporstand
	}
	return 0;
}				
