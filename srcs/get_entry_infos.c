/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_entry_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:35:44 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/30 19:45:20 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*set_pw_name(struct stat st)
{
	struct passwd	*pwd;
	char			*owner;

	if ((pwd = getpwuid(st.st_uid)) != NULL)
		owner = ft_strdup(pwd->pw_name);
	else
		owner = ft_strdup(ft_itoa(st.st_uid));
	return (owner);
}

char				*set_gr_name(struct stat st)
{
	struct group	*grp;
	char			*group;

	if ((grp = getgrgid(st.st_gid)) != NULL)
		group = ft_strdup(grp->gr_name);
	else
		group = ft_itoa(st.st_gid);
	return (group);
}

char				*set_time(struct stat st)
{
	struct tm		*tm;
	char			*datestring;

	tm = localtime(&st.st_mtime);
	datestring = ft_strnew(256);
	strftime(datestring, 256, nl_langinfo(D_T_FMT), tm);
	return (datestring);
}

char				*set_dir_perms(struct stat st)
{
	char			*perms;

	perms = ft_strdup("----------");
	if (S_ISDIR(st.st_mode))
		perms[0] = 'd';
	else if ((st.st_mode & S_IFMT) == S_IFLNK)
		perms[0] = 'l';
	else
		perms[0] = '-';
	perms[1] = st.st_mode & S_IRUSR ? 'r' : '-';
	perms[2] = st.st_mode & S_IWUSR ? 'w' : '-';
	perms[3] = st.st_mode & S_IXUSR ? 'x' : '-';
	perms[4] = st.st_mode & S_IRGRP ? 'r' : '-';
	perms[5] = st.st_mode & S_IWGRP ? 'w' : '-';
	perms[6] = st.st_mode & S_IXGRP ? 'x' : '-';
	perms[7] = st.st_mode & S_IROTH ? 'r' : '-';
	perms[8] = st.st_mode & S_IWOTH ? 'w' : '-';
	if (st.st_mode & S_ISVTX)
		perms[9] = 't';
	else
		perms[9] = st.st_mode & S_IXOTH ? 'x' : '-';
	return (perms);
}

char				*get_nano_seconds(long int tv_nsec)
{
	char			*secs;
	size_t			i;

	i = 0;
	secs = ft_itoa(tv_nsec);
	while ((i + ft_strlen(secs)) < 9)
	{
		secs = ft_strjoin("0", secs);
		i++;
	}
	return (secs);
}
