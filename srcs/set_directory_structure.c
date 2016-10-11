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

static char         *set_pw_name(struct stat st)
{
    struct passwd   *pwd;
    char            *owner;

    if ((pwd = getpwuid(st.st_uid)) != NULL)
        owner = ft_strdup(pwd->pw_name);
    else
        owner = ft_strdup(ft_itoa(st.st_uid));
    return (owner);
}

static char         *set_dir_perms(struct stat st)
{
    char            *perms;

    perms = ft_strdup("----------");
    perms[0] = S_ISDIR(st.st_mode) ? 'd' : '-';
    perms[1] = st.st_mode & S_IRUSR ? 'r' : '-';
    perms[2] = st.st_mode & S_IWUSR ? 'w' : '-';
    perms[3] = st.st_mode & S_IXUSR ? 'x' : '-';
    perms[4] = st.st_mode & S_IRGRP ? 'r' : '-';
    perms[5] = st.st_mode & S_IWGRP ? 'w' : '-';
    perms[6] = st.st_mode & S_IXGRP ? 'x' : '-';
    perms[7] = st.st_mode & S_IROTH ? 'r' : '-';
    perms[8] = st.st_mode & S_IWOTH ? 'w' : '-';
    perms[9] = st.st_mode & S_IXOTH ? 'x' : '-';
    return perms;
}

static void         add_dir(t_dir **dir, char *n, struct stat st, char opt[6])
{
    t_dir           *new_dir;
    char            *long_format;

    new_dir = (t_dir *)malloc(sizeof(t_dir));
    (*dir)->name = ft_strdup(n);
    long_format = ft_strchr(opt, 'l');
    (*dir)->st_mode = long_format != NULL ? st.st_mode : 0;
    (*dir)->perms = long_format != NULL ? ft_strdup(set_dir_perms(st)) : NULL;
    (*dir)->st_nlink = long_format != NULL ? st.st_nlink : 0;
    (*dir)->pw_name = long_format != NULL ? set_pw_name(st) : NULL;
    (*dir)->next = new_dir;

//    /* Print out type, permissions, and number of links. */
//    printf("%10.10s", sperm (statbuf.st_mode));
//    printf("%4d", statbuf.st_nlink);
//
//
//    /* Print out owner's name if it is found using getpwuid(). */
//    if ((pwd = getpwuid(statbuf.st_uid)) != NULL)
//        printf(" %-8.8s", pwd->pw_name);
//    else
//        printf(" %-8d", statbuf.st_uid);
//
//
//    /* Print out group name if it is found using getgrgid(). */
//    if ((grp = getgrgid(statbuf.st_gid)) != NULL)
//        printf(" %-8.8s", grp->gr_name);
//    else
//        printf(" %-8d", statbuf.st_gid);
//
//
//    /* Print size of file. */
//    printf(" %9jd", (intmax_t)statbuf.st_size);
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
}

t_dir        *set_directory_structure(char *dir, t_dir *directory, char options[6])
{
    DIR             *dirp;
    struct dirent   *dp;
    struct stat     statbuf;
    int             i;
    t_dir           *first;

    i = 0;
    if ((dirp = opendir(dir)) == NULL)
        return NULL;
    first = (t_dir *)malloc(sizeof(t_dir));
    while ((dp = readdir(dirp)) != NULL)
    {
        stat(dp->d_name, &statbuf);
        if ((ft_strchr(options, 'a') != NULL && dp->d_name[0] == '.')
            || dp->d_name[0] != '.')
        {
            add_dir(&directory, dp->d_name, statbuf, options);
            first = i == 0 ? directory : first;
            directory = directory->next;
            i++;
        }
    }
    directory->next = NULL;
    closedir(dirp);
    return first;
}