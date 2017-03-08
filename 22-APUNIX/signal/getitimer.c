/* ************************************************************************
 *       Filename:  getitimer.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2016年12月14日 11时43分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/



/*************************************************************************
    > File Name: getitimer.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年12月14日 星期三 11时43分14秒
 ************************************************************************/

#include <stdio.h>
#include <sys/time.h>
int main(int argc, char *argv[])
{
	int tmp;
	struct itimerval demo;
	tmp=getitimer(ITIMER_REAL,&demo);
	printf("1 %lld\n",demo.it_interval.tv_sec);
	printf("2 %llu\n",demo.it_value.tv_sec);
		

	return 0;
}
