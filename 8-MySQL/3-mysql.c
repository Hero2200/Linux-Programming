/*
 * =====================================================================================
 *       Filename:  3-mysql.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年03月05日 21时16分16秒
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
	MYSQL stu,*tmp;
	mysql_init(&stu);
	tmp = mysql_real_connect(&stu,"localhost","root",
			"2200","user",0,NULL,0);
	if(tmp){
		printf ( "connect ok\n" );
		mysql_close(&stu);
	}else{
		printf ( "connect failed\n" );
		if(mysql_error(&stu)){
			fprintf(stderr,"connect error %d:%s\n",
					mysql_errno(&stu),mysql_error(&stu));
		}
	}

	return 0;
}
