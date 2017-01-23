/*
 * =====================================================================================
 *       Filename:  17-gethostid.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时47分53秒
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
int main ( int argc, char *argv[] )
{
	long val;
	val=gethostid();
	printf ( "%ld\n",val );
	return 0;
}				
