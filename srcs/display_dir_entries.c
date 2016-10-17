//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <stdlib.h>

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

static void display_dir(t_dir *dir, char options[6], int max_len)
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
        display_time(dir->time);
        ft_putstr(" ");
    }
    ft_putstr(" ");
    ft_putstr(ft_itoa((int)dir->st_mtimespec));
    ft_putstr(" ");
    ft_putendl(dir->name);

}

void        display_dir_entries(char *dir, char options[6])
{
    t_dir   *directory;
    t_dir   *buf;
    int     max_size_len;

    directory = (t_dir *)malloc(sizeof(t_dir));
    directory->name = NULL;
    directory->next = NULL;
    buf = directory;
    directory = set_directory_structure(dir, buf, options);
    if (directory == NULL)
        return ;
    if (ft_strchr(options, 'r') == NULL && directory->next != NULL)
        sort_list(directory, 1);
    else if (directory->next != NULL)
        sort_list(directory, 0);
    buf = directory;
    max_size_len = display_total_blocks(buf, options);
    while (directory->next != NULL)
    {
        display_dir(directory, options, max_size_len);
        directory = directory->next;
    }
}