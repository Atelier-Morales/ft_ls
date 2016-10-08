//
// Created by Fernan MORALES on 10/8/16.
//

#include "../includes/ft_ls.h"

static void     print_option_error(char c)
{
    ft_putstr("ls: illegal option -- ");
    ft_putchar(c);
    ft_putchar('\n');
    ft_putstr("usage: ls [-altrR] [file ...]");
}

int             check_errors(char option[6], char *av)
{
    size_t  i;

    i = 0;
    if (av[0] == '-')
    {
        i++;
        while (i < ft_strlen(av))
        {
            if (ft_strchr("altrR", av[i]) == NULL)
            {
                print_option_error(av[i]);
                return (0);
            }
            else if (ft_strchr(option, av[i]) == NULL) {
                option[(int)ft_strlen(option)] = av[i];
            }

            i++;
        }
    }
    else
        return (2);
    return (1);
}