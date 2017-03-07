/*
 * =====================================================================================
 *       Filename:  8-mysql_use_result.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年03月07日 21时12分42秒
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

void display_row(MYSQL *tab, MYSQL_ROW sqlrow)
{
	unsigned int count=0;
	while((count < mysql_field_count(tab))){

		printf ( "%s\n",sqlrow[count++] );
	}
	printf ( "\n" );
}

int main ( int argc, char *argv[] )
{
	MYSQL stu;
	MYSQL_RES *res;
	MYSQL_ROW sqlrow;
	int ret;

	mysql_init(&stu);
	if(mysql_real_connect(&stu,"localhost","root","2200",
				"stu",0,NULL,0)){

		printf ( "Connect success\n" );
		ret = mysql_query(&stu,"select * from stu;");
		if(ret){

			printf ( "query failed\n" );
		}else{
			res = mysql_use_result(&stu);
			if(res){
				while((sqlrow = mysql_fetch_row(res))){

					printf ( "Fetch data...\n" );
					display_row(&stu,sqlrow);
				}

			}

		}
	}
	mysql_close(&stu);
	return 0;
}
