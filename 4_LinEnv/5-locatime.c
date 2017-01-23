/*
 * =====================================================================================
 *       Filename:  5-locatime.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时24分42秒
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
	struct tm *tm1,*tm2;
	struct tm *tm;
	time_t time1;
	time1=time(NULL);
	tm2=gmtime(&time1);
	tm1=localtime(&time1);
	tm=tm1;
	printf ( "%d-%d-%d\n",tm->tm_year,tm->tm_mon,tm->tm_mday );
	tm=tm2;
	printf ( "%d-%d-%d\n",tm->tm_year,tm->tm_mon,tm->tm_mday );

	return 0;
}				
