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
#include <stdlib.h>

void        display_dir_entries(char *dir, char options[6])
{
    t_dir   *directory;
    t_dir   *temp;
    int     k;

    k = 0;
    directory = (t_dir *)malloc(sizeof(t_dir));
    directory->name = NULL;
    directory->next = NULL;
    directory = set_directory_structure(dir, directory, options);
    if (ft_strchr(options, 'r') == NULL)
        sort_list(directory, 1);
    else
        sort_list(directory, 0);
    temp = NULL;
    temp = directory;
    while (temp->next != NULL)
    {
//        ft_putendl(directory->name);
        temp = temp->next;
    }

//    while (k < ft_tabcount(directory))
//    {
//        ft_putendl(directory[k]);
//        k++;
//    }
}