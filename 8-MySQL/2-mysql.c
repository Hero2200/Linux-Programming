/*
 * =====================================================================================
 *       Filename:  1-mysql.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年03月05日 17时41分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
int main ( int argc, char *argv[] )
{
	MYSQL tmp;
	mysql_init(&tmp);
//	if(!tmp)
//		perror("MYSQL inti failed");

	if(mysql_real_connect(&tmp, "localhost","root","2200",
			"stu",0,NULL,0) ){
		printf ( "connecttion mysql ok\n" );
	}else{
		printf ( "connection failed\n" );
	}

	printf ( "%d -- %s\n", mysql_errno(&tmp),mysql_error(&tmp));
	mysql_close(&tmp);
	return 0;
}
