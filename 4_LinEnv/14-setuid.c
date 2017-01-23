/*
 * =====================================================================================
 *       Filename:  14-setuid.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时25分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include "demo.h"
int main ( int argc, char *argv[] )
{

	printf ( "euid %d\n",geteuid() );
	printf ( "egid %d\n",getegid() );
	setuid(1000);
	printf ( "uid %d\n",getuid() );
	printf ( "euid %d\n",geteuid() );
	printf ( "gid %d\n",getgid() );
	printf ( "egid %d\n",getegid() );
	return 0;
}				
