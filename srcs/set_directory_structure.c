/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_directory_structure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:49:38 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/30 19:56:08 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <limits.h>
#include <grp.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <stdint.h>
#include <mach/mach.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char			*get_lnk(struct stat st, char *perms, char *name)
{
	char			*link_name;
	size_t			buff_size;
	size_t			i;

	if (perms[0] != 'l')
		return (NULL);
	buff_size = st.st_size == 0 ? PATH_MAX : st.st_size + 1;
	link_name = ft_strnew(buff_size);
	i = readlink(name, link_name, buff_size);
	link_name[i] = '\0';
	return (link_name);
}

static char			*get_name(char *dir)
{
	int				len;
	char			**split;

	split = ft_strsplit(dir, '/');
	len = ft_tabcount(split);
	return (split[len - 1]);
}

static void			add_dir(t_dir **dir, char *n, struct stat st, char opt[6])
{
	t_dir			*new_dir;
	char			*lf;
	char			*sec;
	char			*n_sec;

	new_dir = (t_dir *)malloc(sizeof(t_dir));
	(*dir)->name = get_name(n);
	lf = ft_strchr(opt, 'l');
	(*dir)->st_mode = lf != NULL ? st.st_mode : 0;
	(*dir)->perms = ft_strdup(set_dir_perms(st));
	(*dir)->st_nlink = lf != NULL ? st.st_nlink : 0;
	(*dir)->pw_name = lf != NULL ? set_pw_name(st) : NULL;
	(*dir)->gr_name = lf != NULL ? set_gr_name(st) : NULL;
	(*dir)->st_size = lf != NULL ? (int)st.st_size : 0;
	(*dir)->time = lf != NULL ? set_time(st) : NULL;
	(*dir)->blocks = lf != NULL ? (int)st.st_blocks : 0;
	(*dir)->st_mtimespec = (long long)st.st_mtimespec.tv_sec;
	(*dir)->tv_nsec = st.st_mtimespec.tv_nsec;
	sec = ft_strjoin(ft_itoa(st.st_mtimespec.tv_sec), ".");
	n_sec = get_nano_seconds(st.st_mtimespec.tv_nsec);
	(*dir)->timestamp = ft_strjoin(sec, n_sec);
	(*dir)->linkname = lf ? ft_strdup(get_lnk(st, (*dir)->perms, n)) : NULL;
	(*dir)->next = new_dir;
	(*dir) = (*dir)->next;
}

t_dir				*set_dir(char *dir, t_dir *dr, char opt[6], struct stat st)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				i;
	t_dir			*ft;
	char			*elem;

	i = 0;
	if ((dirp = opendir(dir)) == NULL)
		return (NULL);
	ft = (t_dir *)malloc(sizeof(t_dir));
	while ((dp = readdir(dirp)) != NULL)
	{
		elem = ft_strjoin(ft_strjoin(dir, "/"), dp->d_name);
		lstat(elem, &st);
		if ((ft_strchr(opt, 'a') != NULL && dp->d_name[0] == '.')
				|| dp->d_name[0] != '.')
		{
			ft = i == 0 ? dr : ft;
			add_dir(&dr, elem, st, opt);
			i++;
		}
	}
	closedir(dirp);
	dr->next = NULL;
	return (ft);
}
