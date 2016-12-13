/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterative_display_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:39:56 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/03 15:44:41 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_dir(char *dir)
{
	struct stat file_stat;

	if (stat(dir, &file_stat) < 0)
		return (0);
	return (S_ISDIR(file_stat.st_mode));
}

void			display_dir_errors(char **dirs)
{
	struct stat	path_stat;
	char		*buf;
	int			i;

	i = 0;
	while (i < ft_tabcount(dirs))
	{
		stat(dirs[i], &path_stat);
		if (!check_dir(dirs[i]))
		{
			buf = ft_strjoin(ft_strjoin("ls: '", dirs[i]), \
					"' : No such file or directory\n");
			ft_putstr_fd(buf, 2);
			dirs[i] = ft_strdup("");
		}
		i++;
	}
}

void			iterative_display_mode(char **dirs, char options[6])
{
	int			i;

	i = 0;
	if (ft_strchr(options, 't') == NULL)
		ft_arr_sort(dirs, sort_strcmp, options);
	else
		ft_arr_sort(dirs, sort_dir_time, options);
	display_dir_errors(dirs);
	while (i < ft_tabcount(dirs))
	{
		if (ft_strlen(dirs[i]) > 0)
		{
			if (ft_tabcount(dirs) > 0)
				ft_putendl(ft_strjoin(dirs[i], ":"));
			display_dir_entries(dirs[i], options);
			if (i + 1 != ft_tabcount(dirs))
				ft_putchar('\n');
		}
		i++;
	}
}
