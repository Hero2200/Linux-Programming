/*
 * =====================================================================================
 *       Filename:  9-mysql_use_result.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年03月07日 22时28分39秒
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

void display_row(MYSQL *sql,MYSQL_ROW row){
	unsigned int count=0;
	while(count < mysql_field_count(sql)){
		printf ( "%s ",row[count] );
		count++;
	}
	printf ( "\n" );
}

int main ( int argc, char *argv[] )
{
	MYSQL sql;
	MYSQL_RES *res;
	MYSQL_ROW sqlrow;
	int ret,count=0;

	mysql_init(&sql);
	if(mysql_real_connect(&sql,"localhost","root",
				"2200","stu",0,NULL,0)){
		ret = mysql_query(&sql,"select * from stu;");
		if(ret){
			printf ( "query failed\n" );}
		else{
			res = mysql_use_result(&sql);
			if(res){
				while((sqlrow = mysql_fetch_row(res))){

					printf ( "Fetch data...\n" );
//					while(count < mysql_field_count(&sql)){
//						printf ( "%s ",sqlrow[count++] );
//					}
//					printf ( "\n" );
				//	display_row(&sql,sqlrow);

					while(count < mysql_field_count(&sql)){

						printf ( "%s ",sqlrow[count] );
						count++;
					}
						printf ( "\n" );
				}
			}
		}

	}
	mysql_close(&sql);

	return 0;
}
