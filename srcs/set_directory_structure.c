//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <limits.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
//#include <sys/timespec.h> //remove if OSX
#include <mach/mach.h> // remove if LINUX
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

static char         *set_gr_name(struct stat st)
{
    struct group    *grp;
    char            *group;

    if ((grp = getgrgid(st.st_gid)) != NULL)
        group = ft_strdup(grp->gr_name);
    else
        group = ft_itoa(st.st_gid);
    return (group);
}

static char         *set_time(struct stat st)
{
    struct tm       *tm;
    char            *datestring;

    tm = localtime(&st.st_mtime);
    datestring = ft_strnew(256);
    strftime(datestring, 256, nl_langinfo(D_T_FMT), tm);
    return datestring;
}

static char         *set_dir_perms(struct stat st)
{
    char            *perms;

    perms = ft_strdup("----------");
    perms[0] = S_ISDIR(st.st_mode) ? 'd' : (st.st_mode & S_IFMT) == S_IFLNK ? 'l' : '-';
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

char                *get_nano_seconds(long int tv_nsec)
{
    char            *secs;
    size_t          i;

    i = 0;
    secs = ft_itoa(tv_nsec);
    while ((i + ft_strlen(secs)) < 9)
    {
        secs = ft_strjoin("0", secs);
        i++;
    }
    return secs;
}

static char         *get_lnk(struct stat st, char *perms, char *name)
{
    char            *link_name;
    size_t         buff_size;
    size_t         i;

    if (perms[0] != 'l')
        return NULL;
    buff_size = st.st_size == 0 ? PATH_MAX : st.st_size + 1;
    link_name = ft_strnew(buff_size);
    i = readlink(name, link_name, buff_size);
    link_name[i] = '\0';
    return (link_name);
}

static void         add_dir(t_dir **dir, char *n, struct stat st, char opt[6])
{
    t_dir           *new_dir;
    char            *long_format;
    char            *sec;
    char            *n_sec;

    new_dir = (t_dir *)malloc(sizeof(t_dir));
    (*dir)->name = ft_strdup(n);
    long_format = ft_strchr(opt, 'l');
    (*dir)->st_mode = long_format != NULL ? st.st_mode : 0;
    (*dir)->perms = long_format != NULL ? ft_strdup(set_dir_perms(st)) : NULL;
    (*dir)->st_nlink = long_format != NULL ? st.st_nlink : 0;
    (*dir)->pw_name = long_format != NULL ? set_pw_name(st) : NULL;
    (*dir)->gr_name = long_format != NULL ? set_gr_name(st) : NULL;
    (*dir)->st_size = long_format != NULL ? (int)st.st_size : 0;
    (*dir)->time = long_format != NULL ? set_time(st): NULL;
    (*dir)->blocks = long_format != NULL ? (int)st.st_blocks : 0;
    (*dir)->st_mtimespec = (long long)st.st_mtimespec.tv_sec;
    (*dir)->tv_nsec = st.st_mtimespec.tv_nsec;
    sec = ft_strjoin(ft_itoa(st.st_mtimespec.tv_sec), ".");
    n_sec = get_nano_seconds(st.st_mtimespec.tv_nsec);
    (*dir)->timestamp = ft_strjoin(sec, n_sec);
    (*dir)->linkname = long_format != NULL ? ft_strdup(get_lnk(st, (*dir)->perms, (*dir)->name)) : NULL;
    (*dir)->next = new_dir;
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
        lstat(ft_strjoin(ft_strjoin(dir, "/"), dp->d_name), &statbuf);
        if ((ft_strchr(options, 'a') != NULL && dp->d_name[0] == '.')
            || dp->d_name[0] != '.')
        {
            add_dir(&directory, dp->d_name, statbuf, options);
            first = i == 0 ? directory : first;
            directory = directory->next;
            i++;
        }
    }
    closedir(dirp);
    directory->next = NULL;
    return first;
}