//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <stdlib.h>

static void display_dir(t_dir *dir, char options[6])
{
    char            *long_format;

    long_format = ft_strchr(options, 'l');

    if (long_format != NULL)
    {
        ft_putstr(dir->perms);
        ft_putstr("+ ");
        ft_putnbr(dir->st_nlink);
        ft_putstr(" ");
        ft_putstr(dir->pw_name);
        ft_putstr(" ");
    }
    ft_putendl(dir->name);
}

void        display_dir_entries(char *dir, char options[6])
{
    t_dir   *directory;

    directory = (t_dir *)malloc(sizeof(t_dir));
    directory->name = NULL;
    directory->next = NULL;
    directory = set_directory_structure(dir, directory, options);
    if (directory == NULL)
        return ;
    if (ft_strchr(options, 'r') == NULL && directory->next != NULL)
        sort_list(directory, 1);
    else if (directory->next != NULL)
        sort_list(directory, 0);
    while (directory->next != NULL)
    {
        display_dir(directory, options);
        directory = directory->next;
    }
}