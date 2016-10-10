//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"
#include <stdlib.h>

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
        ft_putendl(directory->name);
        directory = directory->next;
    }
}