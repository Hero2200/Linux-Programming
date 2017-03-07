/*
 * =====================================================================================
 *       Filename:  7-mysql_use_result.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年03月07日 20时53分50秒
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

	MYSQL stu;
	MYSQL_ROW sqlrow;
void display_row(){
	unsigned int count=0;
	while(count < mysql_field_count(&stu)){

		printf ( "%s\n",sqlrow[count] );
		count++;
	}
	printf ( "\n" );
}

int main ( int argc, char *argv[] )
{
	MYSQL_RES *res;
	int ret;

	printf ( "---------------\n" );
	mysql_init(&stu);
	if(mysql_real_connect(&stu,"localhost","root",
				"2200","stu",0,NULL,0)){

		printf ( "connect success\n" );
		ret = mysql_query(&stu,"select * from stu");
		if(ret){

			printf ( "select error:%s\n",mysql_error(&stu) );
		}else{
			res = mysql_use_result(&stu);
			if(res){
				while((sqlrow = mysql_fetch_row(res))){
					printf ( "Fetch data...\n" );
					display_row();
				}
			}
		}
	}
	return 0;
}
