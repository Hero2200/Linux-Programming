/*
 * =====================================================================================
 *       Filename:  15-uname.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时33分47秒
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
#include <sys/utsname.h>
int main ( int argc, char *argv[] )
{
	struct utsname info;
	uname(&info);

	printf ( "arch info\n" );
//	printf ( "%s %s %s %s %s\n",info->sysname,info->nodename,info->release,info->version,info->machine );
	printf ( "%s %s %s %s %s\n",info.sysname,info.nodename,info.release,info.version,info.machine );
	return 0;
}				
