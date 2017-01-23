/*
 * =====================================================================================
 *       Filename:  13-getpwent.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年01月21日 15时21分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *   Organization:  
 * =====================================================================================
 */
#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
main()
{
    struct passwd *user;
    int count=1;
    while((user = getpwent()) != 0)
    {
         printf("count:%d %s:%d:%d:%s:%s:%s\n",count++, user->pw_name, user->pw_uid, user->pw_gid,
        user->pw_gecos, user->pw_dir, user->pw_shell);
    }
    endpwent();
}
