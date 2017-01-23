/*
 * =====================================================================================
 *       Filename:  18-syslog.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时54分35秒
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
#include <syslog.h>
int main ( int argc, char *argv[] )
{
	char buf[256]="112233445566";
	syslog(LOG_INFO,buf);
	return 0;
}				
