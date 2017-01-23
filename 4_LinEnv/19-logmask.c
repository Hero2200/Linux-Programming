/*
 * =====================================================================================
 *       Filename:  19-logmask.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 17时43分34秒
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
	int logmask;
	openlog("liuj-logmask",LOG_PID|LOG_CONS,LOG_USER);
	syslog(LOG_INFO,"informative message,pid=%d",getpid());
	syslog(LOG_DEBUG,"Debug message,should appear");
	logmask=setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_DEBUG,"Debug message,should no appear");
	return 0;
}				
