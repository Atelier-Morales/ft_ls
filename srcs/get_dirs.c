/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:40:15 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/19 19:52:45 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	**create_subdirs(t_dir *buf, int len, char *root)
{
	int		i;
	char	**subs;

	i = 0;
	subs = (char **)malloc(sizeof(char *) * (len + 1));
	while (buf->next != NULL)
	{
		if (buf->perms[0] == 'd' && ft_strcmp(buf->name, ".") != 0 \
				&& ft_strcmp("..", buf->name) != 0)
		{
			subs[i] = ft_strjoin(root, buf->name);
			++i;
		}
		buf = buf->next;
	}
	subs[i] = "\0";
	return (subs);
}

char		**get_dirs(t_dir *dir, char *root)
{
	t_dir	*buf;
	int		len;

	buf = (t_dir *)malloc(sizeof(t_dir));
	buf = dir;
	len = 0;
	while (buf->next != NULL)
	{
		if (buf->perms[0] == 'd' && ft_strcmp(buf->name, ".") != 0 \
				&& ft_strcmp("..", buf->name) != 0)
			++len;
		buf = buf->next;
	}
	buf = dir;
	return (create_subdirs(buf, len, root));
}
