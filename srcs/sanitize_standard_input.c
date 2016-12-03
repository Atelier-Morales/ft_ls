/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_standard_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:11:01 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/03 16:18:55 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			sanitize_standard_input(char **av, int ac, char options[6])
{
	int		ret;
	char	**dirs;

	ret = check_errors(options, av);
	if (ret == -1)
		return (0);
	dirs = ft_strtabdup(av + ret);
	if (ft_strchr(options, 'R') == NULL)
	{
		if (ret == ac - 1)
			display_dir_entries(".", options);
		else
			iterative_display_mode(dirs, options);
	}
	else
		recursive_display_mode(dirs, options);
	return (1);
}
