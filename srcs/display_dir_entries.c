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

void        display_dir_entries(char *dir)
{
    char    **directory;
    int     k;

    k = 0;
    directory = set_directory_structure(dir);

    ft_arr_sort(directory, sort_strcmp, 0);
    while (k < ft_tabcount(directory))
    {
        ft_putendl(directory[k]);
        k++;
    }
}