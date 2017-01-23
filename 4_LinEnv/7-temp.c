/*
 * =====================================================================================
 *       Filename:  7-temp.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 12时52分47秒
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
	char *temp;
	char buf[256];
	temp=tmpnam(buf);
	printf ( "%s\n",temp );
	printf ( "%s\n",buf );
	return 0;
}				
