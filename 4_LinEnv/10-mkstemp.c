/*
 * =====================================================================================
 *       Filename:  10-mkstemp.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 14时23分36秒
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
	int fd;
	char buf[]="liuj-XXXXXX";
	fd=mkstemp(buf);

	printf ( "%s\n",buf );
	printf ( "%d\n",fd );
	return 0;
}				
