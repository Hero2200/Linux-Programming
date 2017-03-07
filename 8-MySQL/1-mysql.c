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
	MYSQL *stu_sql,tmp;
	stu_sql = mysql_init(NULL);
	if(!stu_sql)
		perror("MYSQL inti failed");

	mysql_real_connect(stu_sql, "localhost","root","as",
			"stu",0,NULL,0);
	if(!stu_sql)
		printf ( "connection failed\n" );
	mysql_close(stu_sql);
	return 0;
}
