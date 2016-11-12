//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"

void display_dir_errors(char **dirs)
{
    struct stat path_stat;
    char    *buf;
    int     i;

    i = 0;
    while (i < ft_tabcount(dirs))
    {
        stat(dirs[i], &path_stat);
        if (S_ISDIR(path_stat.st_mode) == 0)
        {
            buf = ft_strjoin(ft_strjoin("ls: '", dirs[i]), \
            "' : No such file or directory\n");
            ft_putstr_fd(buf, 2);
        }
        i++;
    }
}

int  check_dir(char *dir)
{
    struct stat path_stat;
    int     ret;

    ret = 1;
    stat(dir, &path_stat);
    if (S_ISDIR(path_stat.st_mode) == 0)
        ret = 0;
    return (ret);
}

void    iterative_display_mode(char **dirs,char options[6])
{
    int i;

    i = 0;
    if (ft_strchr(options, 't') == NULL)
        ft_arr_sort(dirs, sort_strcmp, options);
    else
        ft_arr_sort(dirs, sort_dir_time, options);
    display_dir_errors(dirs);
    while (i < ft_tabcount(dirs) && check_dir(dirs[i]) != 0)
    {
        if (ft_tabcount(dirs) > 1)
            ft_putendl(ft_strjoin(dirs[i], ":"));
        display_dir_entries(dirs[i], options);
        if (i + 1 != ft_tabcount(dirs))
            ft_putchar('\n');
        i++;
    }
}