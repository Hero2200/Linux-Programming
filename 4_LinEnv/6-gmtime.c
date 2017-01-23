/*
 * =====================================================================================
 *       Filename:  6-gmtime.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时33分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "demo.h"
int main ( int argc, char *argv[] )
{
	struct tm *tm,*tm1,*tm2;
	time_t t1,t2;

	t1=time(NULL);
	tm1=gmtime(&t1);
	tm=tm1;
	printf ( "%d-%d-%d\n",tm->tm_year,tm->tm_mon,tm->tm_mday );

	tm2=localtime(&t1);
	tm=tm2;
	printf ( "%d-%d-%d\n",tm->tm_year,tm->tm_mon,tm->tm_mday );

//	sleep(1);
	t2=time(NULL);
	printf ( "%g\n",difftime(t1,t2) );

//	tm->tm_year=2017;
	tm->tm_mday=22;
	t1=mktime(tm);
	printf ( "%g\n",difftime(t1,t2) );
	printf ( "%s\n",asctime(tm1) );
	printf ( "%s\n",ctime(&t1) );
	char str[256]="";
	strftime(str,256,"Date:%Y-%m-%d Time:%H.%M.%S",tm1);
	printf ( "%s\n",str );
	return 0;
}				
