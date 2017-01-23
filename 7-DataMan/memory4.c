/*
 * =====================================================================================
 *       Filename:  memory4.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 22时13分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ( int argc, char *argv[] )
{
	char *tmp;
	tmp=(char *)malloc(1024);
	while(1){
		*tmp++='A';
	}
	return 0;
}				
