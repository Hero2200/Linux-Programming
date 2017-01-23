/*
 * =====================================================================================
 *       Filename:  9-mktemp.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 13时58分03秒
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
	char buf[]="aabbcci-XXXXXX";
	char *var;
	int fd;
	var=mktemp(buf);
	printf ( "%s\n",buf );
	printf ( "%s\n",var );
	fd=mkstemp("liuj-XXXXXX");
	printf ( "%d\n",fd );
	return 0;
}				
