/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 03:17:17 by fmorales          #+#    #+#             */
/*   Updated: 2014/05/10 20:23:13 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static int		no_leak_exit(char **mem, int ret)
{
	free(*mem);
	*mem = NULL;
	return (ret);
}

static int		cut_endl(char **mem, char **line, char *endl)
{
	char		*tmp;

	tmp = *mem;
	if (endl == NULL)
		endl = ft_strdup("\0");
	if (!(*line = ft_strsub(*mem, 0, endl - (*mem)))
		|| !(*mem = ft_strsub(endl + 1, 0, ft_strlen(endl + 1))))
		return (no_leak_exit(&tmp, -1));
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t		sz;
	char		*tmp;
	char		*endl;
	static char	*mem;
	char		buff[BUFF_SIZE + 1];

	if ((sz = 1) && !line)
		return (-1);
	while ((!mem || (!(endl = ft_strchr(mem, '\n')) && endl))
			&& (sz = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[sz] = '\0';
		if (!mem && !(mem = ft_strnew(0)))
			return (-1);
		tmp = mem;
		if (!(mem = ft_strjoin(mem, buff)))
			return (no_leak_exit(&tmp, -1));
		free(tmp);
	}
	if (sz == -1 || !mem || !*mem)
		return (no_leak_exit(&mem, (sz == -1) ? -1 : 0));
	if (sz == 0 && (*line = mem))
		return (1 + *((int*)(mem = NULL)));
	return (cut_endl(&mem, line, endl));
}
