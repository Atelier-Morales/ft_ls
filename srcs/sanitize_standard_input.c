//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"

int sanitize_standard_input(char **av)
{
    char        options[6];
    int         i;
    int         ret;
    int         start;
    char        **dirs;

    i = 0;
    ft_bzero(options, 6);
    ret = check_errors(options, av[0]);
    start = (ret == 2) ? 0 : 1;
    if (ret == 0)
        return (0);
    dirs = ft_strtabdup(av + start);
    if (ft_strchr(options, 'R') == NULL)
        iterative_display_mode(dirs, options);
    ft_putstr("options = ");
    ft_putendl(options);
    return (1);
}