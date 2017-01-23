/*
 * =====================================================================================
 *       Filename:  memory6.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 22时17分56秒
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
	tmp=(char *)malloc(1024);
	sprintf(tmp,"Hellow world");
		printf ( "%s\n",tmp );
		free(tmp);
	return 0;
}				
