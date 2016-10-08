//
// Created by Fernan on 05/10/2016.
//

#include "../includes/ft_ls.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        display_dir_entries(".");
    }
    else
        sanitize_standard_input(++av);
    ft_putstr("\n");
    (void)av;
    return (0);
}