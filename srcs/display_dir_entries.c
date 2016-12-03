/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir_entries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:23:33 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/03 16:10:34 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		print_symlink(char *linkname)
{
	if (linkname == NULL)
		return ;
	ft_putstr(" -> ");
	ft_putstr(linkname);
}

static void		display_time_osx(char *datestring)
{
	char		**splitted;

	splitted = ft_strsplit(datestring, ' ');
	ft_putstr(splitted[1]);
	ft_putstr(" ");
	if (ft_strlen(splitted[2]) == 1)
		ft_putstr(" ");
	ft_putstr(splitted[2]);
	ft_putstr(" ");
	ft_putstr(ft_strsub(splitted[3], 0, 5));
}

static void		ft_putstr_sp(char *src, int len)
{
	int			i;

	i = 0;
	ft_putstr(src);
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
}

void			display_dir_osx(t_dir *dir, char opt[6], int len, int max_links)
{
	char		*long_format;
	int			i;

	i = -1;
	long_format = ft_strchr(opt, 'l');
	if (long_format != NULL)
	{
		ft_putstr_sp(dir->perms, 2);
		while (++i < (max_links - (int)ft_strlen(ft_itoa(dir->st_nlink))))
			ft_putstr(" ");
		i = -1;
		ft_putnbr(dir->st_nlink);
		ft_putstr(" ");
		ft_putstr_sp(dir->pw_name, 2);
		ft_putstr_sp(dir->gr_name, 2);
		while (++i < (len - (int)ft_strlen(ft_itoa(dir->st_size))))
			ft_putstr(" ");
		ft_putstr(ft_itoa(dir->st_size));
		ft_putstr(" ");
		display_time_osx(dir->time);
		ft_putstr(" ");
	}
	ft_putstr(dir->name);
	print_symlink(dir->linkname);
}

void			display_dir_entries(char *dir, char options[6])
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
		return ;
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
}
