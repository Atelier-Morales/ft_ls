/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir_entries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:23:33 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/09 21:55:27 by fmorales         ###   ########.fr       */
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

static void		display_time_osx(char *datestring)
{
	char		**splitted;

	splitted = ft_strsplit(datestring, ' ');
	ft_putstr_sp(splitted[1], 1);
	if (ft_strlen(splitted[2]) == 1)
		ft_putstr(" ");
	ft_putstr_sp(splitted[2], 1);
	ft_putstr(ft_strsub(splitted[3], 0, 5));
}

void			display_dir_osx(t_dir *dir, char opt[6], t_len *len)
{
	char		*long_format;
	int			i;

	i = -1;
	long_format = ft_strchr(opt, 'l');
	if (long_format != NULL)
	{
		ft_putstr_sp(dir->perms, 2);
		print_void(len->max_ln, (int)ft_strlen(ft_itoa(dir->st_nlink)));
		ft_putstr_sp(ft_itoa(dir->st_nlink), 1);
		ft_putstr_sp(dir->pw_name, 2);
		print_void(len->max_ow, (int)ft_strlen(dir->pw_name));
		ft_putstr_sp(dir->gr_name, 2);
		print_void(len->max_gr, (int)ft_strlen(dir->gr_name));
		print_void(len->max_sz, (int)ft_strlen(ft_itoa(dir->st_size)));
		ft_putstr_sp(ft_itoa(dir->st_size), 1);
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
	t_len		*len;

	directory = (t_dir *)malloc(sizeof(t_dir));
	buf = directory;
	st = (struct stat*)malloc(sizeof(struct stat));
	directory = set_dir(dir, buf, options, *st);
	if (directory == NULL)
		return ;
	set_sorting_rules(&directory, options);
	buf = directory;
	len = (t_len *)malloc(sizeof(t_len));
	get_right_padding(&len, buf, options);
	while (directory->next != NULL)
	{
		display_dir_osx(directory, options, len);
		ft_putchar('\n');
		directory = directory->next;
	}
	free(len);
}
