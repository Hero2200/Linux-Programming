/* ************************************************************************
 *       Filename:  alarm.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2016年12月12日 13时22分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/



/*************************************************************************
    > File Name: alarm.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2016年12月12日 星期一 13时22分17秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void my_alarm(int signo)
{
	printf("%s ALARM\n",__func__);
}

int main(int argc, char *argv[])
{
	signal(SIGALRM,my_alarm);
	alarm(1);
	pause();
	return 0;
}
