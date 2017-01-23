/*
 * =====================================================================================
 *       Filename:  15-gethostname.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时29分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo.h"
int main ( int argc, char *argv[] )
{
	char buf[256];
	if((gethostname(buf,256)) == -1)
		perror("gethostname error");

	printf ( "host info:%s\n",buf );

	return 0;
}				
