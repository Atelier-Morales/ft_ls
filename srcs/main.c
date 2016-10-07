//
// Created by Fernan on 05/10/2016.
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

void display_basic_entries(char *dir)
{
    struct dirent   *dp;
    DIR             *dirp;

    dirp = opendir(dir);
    while ((dp = readdir(dirp)) != NULL)
    {
        if (dp->d_name[0] != '.') {
            ft_putstr(dp->d_name);
            ft_putstr("  ");
        }
    }
    closedir(dirp);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        display_basic_entries(".");
    }
    ft_putstr("\n");
    (void)av;
    return (0);
}