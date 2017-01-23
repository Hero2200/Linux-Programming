/*
 * =====================================================================================
 *       Filename:  4-difftime.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时17分10秒
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
#include <time.h>
int main ( int argc, char *argv[] )
{
	time_t t1,t2;
	double tm;
	t1=time(NULL);
	sleep(2);
	t2=time(NULL);

	tm=difftime(t1,t2);
	printf ( "%\n",tm );
	return 0;
}				
