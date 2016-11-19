/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_total_blocks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:32:18 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/19 19:33:07 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		display_total_blocks(t_dir *buf, char options[6])
{
	int	blocks;
	int	max_len;

	blocks = 0;
	max_len = 0;
	if (ft_strchr(options, 'l') == NULL)
		return (0);
	while (buf->next != NULL)
	{
		if ((int)ft_strlen(ft_itoa(buf->st_size)) > max_len)
			max_len = (int)ft_strlen(ft_itoa(buf->st_size));
		blocks += buf->blocks;
		buf = buf->next;
	}
	ft_putendl(ft_strjoin("total ", ft_itoa(blocks)));
	return (max_len);
}
