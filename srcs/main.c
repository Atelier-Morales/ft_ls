/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:31:38 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/13 18:33:53 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	char	options[6];

	ft_bzero(options, 6);
	if (ac == 1)
		display_dir_entries(".", options);
	else
		sanitize_standard_input(++av, ac, options);
	(void)av;
	return (0);
}
