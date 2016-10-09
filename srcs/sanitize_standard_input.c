//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"

int sanitize_standard_input(char **av, int ac, char options[6])
{
    int         i;
    int         ret;
    char        **dirs;

    i = 0;
    ret = check_errors(options, av);
    if (ret == 0)
        return (0);
    dirs = ft_strtabdup(av + ret);
    if (ft_strchr(options, 'R') == NULL) {
        if (ret == ac - 1)
            display_dir_entries(".", options);
        else
            iterative_display_mode(dirs, options);
    }
    return (1);
}