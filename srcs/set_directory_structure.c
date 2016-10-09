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

//static int  get_dir_len(char *dir, char options[6])
//{
//    DIR             *dirp;
//    struct dirent   *dp1;
//    struct stat     statbuf2;
//    int             len;
//
//    len = 0;
//    dirp = opendir(dir);
//    while ((dp1 = readdir(dirp)) != NULL)
//    {
//        if (stat(dp1->d_name, &statbuf2) == -1)
//            continue ;
//        if ((ft_strchr(options, 'a') != NULL && dp1->d_name[0] == '.')
//            || dp1->d_name[0] != '.')
//            len++;
//    }
//    closedir(dirp);
//    return (len);
//}

//static char        *display_long_format(struct stat statbuf, struct dirent   *dp)
//{
//    struct passwd  *pwd;
//    struct group   *grp;
//    struct tm      *tm;
//    char            datestring[256];
//
//    /* Print out type, permissions, and number of links. */
//    printf("%9jd", (intmax_t)statbuf.st_mode);
//    printf("%4d", statbuf.st_nlink);
//
//
//    /* Print out owner's name if it is found using getpwuid(). */
//    if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
//        printf(" %-8.8s ", pwd->pw_name);
//    else
//        printf(" %-8d ", statbuf.st_uid);
//
//
//    /* Print out group name if it is found using getgrgid(). */
//    if ((grp = getgrgid(statbuf.st_gid)) != NULL)
//        printf(" %s ", grp->gr_name);
//    else
//        printf(" %d ", statbuf.st_gid);
//
//    /* Print size of file. */
//    printf(" %5jd", (intmax_t)statbuf.st_size);
//
//
//    tm = localtime(&statbuf.st_mtime);
//
//
//    /* Get localized date string. */
//    strftime(datestring, sizeof(datestring), nl_langinfo(D_T_FMT), tm);
//
//
//    printf(" %s %s\n", datestring, dp->d_name);
//    return (NULL);
//}

static void         add_dir(t_dir **directory, t_dir **first, char *name, int i)
{
    t_dir           *new_dir;

    new_dir = (t_dir *)malloc(sizeof(t_dir));
    (*directory)->name = name;
    (*directory)->next = new_dir;
    if (i == 0)
        *first = *directory;
    *directory = (*directory)->next;
}

t_dir        *set_directory_structure(char *dir, t_dir *directory, char options[6])
{
    DIR             *dirp;
    struct dirent   *dp;
    struct stat     statbuf;
    int             i;
    t_dir           *first;

    i = 0;
    dirp = opendir(dir);
    first = (t_dir *)malloc(sizeof(t_dir));
    while ((dp = readdir(dirp)) != NULL)
    {
        if (stat(dp->d_name, &statbuf) == -1)
            continue;
        if ((ft_strchr(options, 'a') != NULL && dp->d_name[0] == '.')
            || dp->d_name[0] != '.')
        {
//            ret[i] = ft_strchr(options, 'l') != NULL ? display_long_format(statbuf, dp)
//                                                     : ft_strdup(dp->d_name);
            add_dir(&directory, &first, dp->d_name, i);
            i++;
        }
    }
    directory->next = NULL;
    closedir(dirp);
    return first;
}