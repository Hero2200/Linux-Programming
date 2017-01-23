/*
 * =====================================================================================
 *       Filename:  2-environ.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时08分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern char **environ;
int main ( int argc, char *argv[] )
{
	char **env = environ;
	while(*env){
		printf ( "%s\n",*env );
		env++;
	}
	return 0;
}				
