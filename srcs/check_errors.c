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

int             check_errors(char option[6], char **av)
{
    size_t         i;
    size_t         j;

    i = 0;
    while (av[i] != NULL && av[i][0] == '-')
    {
        j = 1;
        while (j < ft_strlen(av[i]))
        {
            if (ft_strchr("altrR", av[i][j]) == NULL)
            {
                print_option_error(av[i][j]);
                return (-1);
            }
            else if (ft_strchr(option, av[i][j]) == NULL) {
                option[(int)ft_strlen(option)] = av[i][j];
            }
            j++;
        }
        i++;
    }
    return (i);
}