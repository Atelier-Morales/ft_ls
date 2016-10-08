//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int  get_dir_len(char *dir)
{
    DIR             *dirp;
    struct dirent   *dp1;
    struct stat     statbuf2;
    int             len;

    len = 0;
    dirp = opendir(dir);
    while ((dp1 = readdir(dirp)) != NULL)
    {
        if (stat(dp1->d_name, &statbuf2) == -1)
            continue ;
        if (dp1->d_name[0] != '.') {
            len++;
        }
    }
    closedir(dirp);
    return (len);
}

char        **set_directory_structure(char *dir)
{
    DIR             *dirp;
    struct dirent   *dp;
    struct stat     statbuf;
    int             i;
    char            **ret;

    i = 0;
    dirp = opendir(dir);
    if (!(ret = (char**)malloc(sizeof(char*) * (get_dir_len(dir) + 1))))
        return (NULL);
    while ((dp = readdir(dirp)) != NULL)
    {
        if (stat(dp->d_name, &statbuf) == -1)
            continue;
        if (dp->d_name[0] != '.') {
            ret[i] = ft_strdup(dp->d_name);
            i++;
        }
    }
    ret[i] = NULL;
    closedir(dirp);
    return (ret);
}