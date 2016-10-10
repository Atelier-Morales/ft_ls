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

static void display_dir_errors(char **dirs)
{
    DIR     *dirp;
    char    *buf;
    int     i;

    i = 0;
    while (i < ft_tabcount(dirs))
    {
        if ((dirp = opendir(dirs[i])) == NULL)
        {
            buf = ft_strjoin(ft_strjoin("ls: '", dirs[i]), \
            "' : No such file or directory\n");
            ft_putstr_fd(buf, 2);
        }
        closedir(dirp);
        i++;
    }
}

static int  check_dir(char *dir)
{
    DIR     *dirp;
    int     ret;

    ret = 1;
    if ((dirp = opendir(dir)) == NULL)
        ret = 0;
    closedir(dirp);
    return (ret);
}

void    iterative_display_mode(char **dirs,char options[6]) {
    int i;

    i = 0;
    if (ft_strchr(options, 'r') == NULL)
        ft_arr_sort(dirs, sort_strcmp, 0);
    else
        ft_arr_sort(dirs, sort_strcmp, 1);
    display_dir_errors(dirs);
    while (i < ft_tabcount(dirs) && check_dir(dirs[i]) != 0)
    {
        ft_putendl(ft_strjoin(dirs[i], ":"));
        display_dir_entries(dirs[i], options);
        if (i + 1 != ft_tabcount(dirs))
            ft_putchar('\n');
        i++;
    }
}