/*
 * =====================================================================================
 *       Filename:  11-getuid.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 14时59分56秒
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
#include <sys/types.h>
#include <pwd.h>
int main ( int argc, char *argv[] )
{
	int val;
	val=getuid();
	printf ( "%d\n",val );
	printf ( "%s\n",getlogin() );

	struct passwd *wd;
	wd=getpwuid(val);
	printf ( "%s:%d:%d:%s:%s:%s\n",wd->pw_name,wd->pw_uid,wd->pw_gid,wd->pw_dir,wd->pw_gecos,wd->pw_shell );
	printf ( "------------------>\n" );

	wd=getpwnam("liuj");
	printf ( "%s:%d:%d:%s:%s:%s\n",wd->pw_name,wd->pw_uid,wd->pw_gid,wd->pw_dir,wd->pw_gecos,wd->pw_shell );

	int i=1;
	while(wd=getpwent()){
		printf ( "%s:%d:%d:%s:%s:%s\n",wd->pw_name,wd->pw_uid,wd->pw_gid,wd->pw_dir,wd->pw_gecos,wd->pw_shell );
		printf ( "%d\n",i++ );
	}
	endpwent();
	return 0;
}				
