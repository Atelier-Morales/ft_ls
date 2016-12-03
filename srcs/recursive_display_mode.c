/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_display_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:26:35 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/03 14:28:54 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_access_error(char *dir)
{
	char		*error;

	error = ft_strjoin("ls: ", ft_strjoin(dir, ": Permission denied\n"));
	ft_putstr_fd(error, 1);
}

t_dir			*rec_entries(char *dir, char options[6])
{
	struct stat	*st;
	t_dir		*directory;
	t_dir		*buf;
	int			max_size_len;
	int			max_links;

	directory = (t_dir *)malloc(sizeof(t_dir));
	buf = directory;
	st = (struct stat*)malloc(sizeof(struct stat));
	directory = set_dir(dir, buf, options, *st);
	if (directory == NULL)
		return (NULL);
	set_sorting_rules(&directory, options);
	buf = directory;
	max_size_len = display_total_blocks(buf, options);
	max_links = get_links_len(buf, options);
	while (directory->next != NULL)
	{
		display_dir_osx(directory, options, max_size_len, max_links);
		ft_putchar('\n');
		directory = directory->next;
	}
	return (buf);
}

void			recursive_display(char **dir, char options[6], int len)
{
	t_dir		*subs;
	int			sublen;
	char		**sub_dirs;
	static int	flag;

	sub_dirs = NULL;
	if (check_dir(*dir) != 0 && ft_strcmp(*dir, "..") != 0)
	{
		if (flag != 0)
			ft_putchar('\n');
		flag++;
		if (len > 1)
			ft_putendl(ft_strjoin(*dir, ":"));
		if ((subs = rec_entries(*dir, options)) && subs != NULL)
		{
			sub_dirs = get_dirs(subs, ft_strjoin(*dir, "/"));
			sublen = ft_tabcount(sub_dirs);
			if (sublen > 0)
				recursive_display(sub_dirs, options, sublen);
		}
		else
			print_access_error(*dir);
	}
	if (ft_tabcount(dir) >= 1)
		recursive_display(++dir, options, len);
}

void			recursive_display_mode(char **dirs, char options[6])
{
	int			len;
	char		*root;

	len = ft_tabcount(dirs);
	root = ft_strdup(".");
	if (len > 0)
	{
		if (ft_strchr(options, 't') == NULL)
			ft_arr_sort(dirs, sort_strcmp, options);
		else
			ft_arr_sort(dirs, sort_dir_time, options);
		display_dir_errors(dirs);
		recursive_display(dirs, options, len);
	}
	else
		recursive_display(&root, options, 1);
	return ;
}
