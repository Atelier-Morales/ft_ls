//
// Created by Fernan on 05/10/2016.
//

#include "../includes/ft_ls.h"

int main(int ac, char **av)
{
    char        options[6];

    ft_bzero(options, 6);
    if (ac == 1) {
        display_dir_entries(".", options);
    }
    else
        sanitize_standard_input(++av, ac, options);
    (void)av;
    return (0);
}