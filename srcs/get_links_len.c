/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:31:02 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/19 19:31:41 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		get_links_len(t_dir *buf, char options[6])
{
	int	max_len;

	max_len = 0;
	if (ft_strchr(options, 'l') == NULL)
		return (0);
	while (buf->next != NULL)
	{
		if ((int)ft_strlen(ft_itoa(buf->st_nlink)) > max_len)
			max_len = (int)ft_strlen(ft_itoa(buf->st_nlink));
		buf = buf->next;
	}
	return (max_len);
}
