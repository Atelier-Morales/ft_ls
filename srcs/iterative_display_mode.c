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

void    iterative_display_mode(char **dirs,char options[6]) {
    int i;

    i = 0;
    if (ft_strchr(options, 'r') == NULL)
        ft_arr_sort(dirs, sort_strcmp, 0);
    else
        ft_arr_sort(dirs, sort_strcmp, 1);
    while (i < ft_tabcount(dirs))
    {
        display_dir_entries(dirs[i], options);
        i++;
    }
}