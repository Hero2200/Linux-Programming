/*
 * =====================================================================================
 *       Filename:  3-time.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时13分21秒
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
int main ( int argc, char *argv[] )
{
	int i;
	time_t the;

	for(i=1;i<=10;i++){
		the=time(NULL);
		printf ( "%d\n",the );
		sleep(2);
	}
	return 0;
}				
