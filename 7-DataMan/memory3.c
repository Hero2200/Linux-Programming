/*
 * =====================================================================================
 *       Filename:  memory3.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 22时08分59秒
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
	char *tmp;
	char buf[]="Hellow world";
	int len=strlen(buf);
	int i,count=0;
	while(1){
		for(i=0; i<1024 ;i++){
			tmp= (char *)malloc(1024*1024);
			sprintf(tmp,buf);
			printf ( "%s\n",tmp );
		}
		count++;
		printf ( "Now malloc %d\n",count );
	}
	return 0;
}				
