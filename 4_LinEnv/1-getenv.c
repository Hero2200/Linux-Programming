/*
 * =====================================================================================
 *       Filename:  1-getenv.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 10时53分36秒
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
	char *var,*value;
	value=getenv("PATH");

	printf ( "%s\n",value );
	return 0;
}				
