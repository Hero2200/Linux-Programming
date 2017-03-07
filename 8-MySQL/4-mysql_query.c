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
	char cmd[512];
	long ret;
	mysql_init(&stu);
	tmp = mysql_real_connect(&stu,"localhost","root",
			"2200","stu",0,NULL,0);
	if(tmp){
		printf ( "connect ok\n" );
//		mysql_query(&stu,"select * from stu;");
		mysql_query(&stu,"update stu set sex=\"gril\" where id=6;");
		ret = mysql_affected_rows(&stu);
		printf ( "ret = %lu\n",ret );

		mysql_query(&stu,"insert stu values(null,\"gg\",\"boy\",17,\"789\",null);");
		ret = mysql_affected_rows(&stu);
		printf ( "ret = %lu\n",ret );
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
