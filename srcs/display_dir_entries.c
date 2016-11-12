//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int display_total_blocks(t_dir *buf, char options[6])
{
    int blocks;
    int max_len;

    blocks = 0;
    max_len = 0;
    if (ft_strchr(options, 'l') == NULL)
        return (0);
    while (buf->next != NULL)
    {
        if ((int)ft_strlen(ft_itoa(buf->st_size)) > max_len)
            max_len = (int)ft_strlen(ft_itoa(buf->st_size));
        blocks += buf->blocks;
        buf = buf->next;
    }
    ft_putendl(ft_strjoin("total ", ft_itoa(blocks)));
    return (max_len);
}

static int get_links_len(t_dir *buf, char options[6])
{
    int max_len;

    max_len = 0;
    if (ft_strchr(options, 'l') == NULL)
        return (0);
    while (buf->next != NULL)
    {
        if ((int)ft_strlen(ft_itoa(buf->st_nlink)) > max_len)
            max_len = (int)ft_strlen(ft_itoa(buf->st_nlink));
        buf = buf->next;
    }
    return (max_len);
}

static void print_symlink(char *linkname)
{
    if (linkname == NULL)
    {
        ft_putstr("\n");
        return ;
    }
    ft_putstr(" -> ");
    ft_putendl(linkname);
}

static void display_time(char *datestring)
{
    char    **splitted;

    splitted = ft_strsplit(datestring, ' ');
    ft_putstr(splitted[2]);
    ft_putstr(" ");
    ft_putstr(lower_str(splitted[1]));
    if (ft_strcmp(splitted[1], "juin") == 0|| \
        ft_strcmp(splitted[1], "aout") == 0 || \
        ft_strcmp(splitted[1], "mars") == 0)
        ft_putstr("  ");
    else if (ft_strcmp(splitted[1], "mai") == 0)
        ft_putstr("   ");
    else
        ft_putstr(".  ");
    ft_putstr(ft_strsub(splitted[3], 0, 5));
}

static void display_time_OSX(char *datestring)
{
    char    **splitted;

    splitted = ft_strsplit(datestring, ' ');
    ft_putstr(splitted[1]);
    ft_putstr(" ");
    if (ft_strlen(splitted[2]) == 1)
        ft_putstr(" ");
    ft_putstr(splitted[2]);
    ft_putstr(" ");
    ft_putstr(ft_strsub(splitted[3], 0, 5));
}

static void display_dir_OSX(t_dir *dir, char options[6], int max_len, int max_links)
{
    char            *long_format;
    int             i;

    i = -1;
    long_format = ft_strchr(options, 'l');
    if (long_format != NULL)
    {
        ft_putstr(dir->perms);
        ft_putstr("  ");
        while (++i < (max_links - (int)ft_strlen(ft_itoa(dir->st_nlink))))
            ft_putstr(" ");
        i = -1;
        ft_putnbr(dir->st_nlink);
        ft_putstr(" ");
        ft_putstr(dir->pw_name);
        ft_putstr("  ");
        ft_putstr(dir->gr_name);
        ft_putstr("  ");
        while (++i < (max_len - (int)ft_strlen(ft_itoa(dir->st_size))))
            ft_putstr(" ");
        ft_putstr(ft_itoa(dir->st_size));
        ft_putstr(" ");
        display_time_OSX(dir->time);
        ft_putstr(" ");
//        ft_putstr(dir->timestamp);
//        ft_putstr(" ");
    }
    ft_putstr(dir->name);
    print_symlink(dir->linkname);
}

static void display_dir(t_dir *dir, char options[6], int max_len, int max_links)
{
    char            *long_format;
    int             i;

    i = -1;
    long_format = ft_strchr(options, 'l');
    if (long_format != NULL)
    {
        ft_putstr(dir->perms);
        if (OS_MODE == 0)
            ft_putstr("+ ");
        else
            ft_putstr(" ");
        while (++i < (max_links - (int)ft_strlen(ft_itoa(dir->st_nlink))))
            ft_putstr(" ");
        i = -1;
        ft_putnbr(dir->st_nlink);
        ft_putstr(" ");
        ft_putstr(dir->pw_name);
        ft_putstr(" ");
        ft_putstr(dir->gr_name);
        ft_putstr(" ");
        while (++i < (max_len - (int)ft_strlen(ft_itoa(dir->st_size))))
            ft_putstr(" ");
        ft_putstr(ft_itoa(dir->st_size));
        ft_putstr(" ");
        if (OS_MODE == 0)
            display_time(dir->time);
        else if (OS_MODE == 1)
            display_time_OSX(dir->time);
        ft_putstr(" ");
    }
    ft_putstr(dir->name);
    print_symlink(dir->linkname);
}

void        set_sorting_rules(t_dir **directory, char options[6])
{
    if (ft_strchr(options, 'r') == NULL \
        && ft_strchr(options, 't') == NULL \
        && (*directory)->next != NULL)
        sort_list(*directory, 1);
    else if (ft_strchr(options, 'r') != NULL \
        && ft_strchr(options, 't') == NULL \
        && (*directory)->next != NULL)
        sort_list(*directory, 0);
    else if (ft_strchr(options, 'r') == NULL \
        && ft_strchr(options, 't') != NULL \
        && (*directory)->next != NULL)
        sort_list_time(*directory, 0);
    else if (ft_strchr(options, 'r') != NULL \
        && ft_strchr(options, 't') != NULL \
        && (*directory)->next != NULL)
        sort_list_time(*directory, 1);
}

void        display_dir_entries(char *dir, char options[6])
{
    t_dir   *directory;
    t_dir   *buf;
    int     max_size_len;
    int     max_links;

    directory = (t_dir *)malloc(sizeof(t_dir));
    directory->name = NULL;
    directory->next = NULL;
    buf = directory;
    directory = set_directory_structure(dir, buf, options);
    if (directory == NULL)
        return ;
    set_sorting_rules(&directory, options);
    buf = directory;
    max_size_len = display_total_blocks(buf, options);
    max_links = get_links_len(buf, options);
    while (directory->next != NULL)
    {
        if (OS_MODE == 0)
            display_dir(directory, options, max_size_len, max_links);
        else if (OS_MODE == 1)
            display_dir_OSX(directory, options, max_size_len, max_links);
        directory = directory->next;
    }
}