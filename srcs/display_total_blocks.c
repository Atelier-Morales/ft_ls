/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_total_blocks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:32:18 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/09 21:53:45 by fmorales         ###   ########.fr       */
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

int		get_max_owner_len(t_dir *buf, char options[6])
{
	int	max_len;

	max_len = 0;
	if (ft_strchr(options, 'l') == NULL)
		return (0);
	while (buf->next != NULL)
	{
		if ((int)ft_strlen(buf->pw_name) > max_len)
			max_len = (int)ft_strlen(buf->pw_name);
		buf = buf->next;
	}
	return (max_len);
}

void    print_void(int len_max, int len_org)
{
	int i;

	i = -1;
	while (++i < (len_max - len_org))
		ft_putstr(" ");
}

int		get_max_group_len(t_dir *buf, char options[6])
{
	int	max_len;

	max_len = 0;
	if (ft_strchr(options, 'l') == NULL)
		return (0);
	while (buf->next != NULL)
	{
		if ((int)ft_strlen(buf->gr_name) > max_len)
			max_len = (int)ft_strlen(buf->gr_name);
		buf = buf->next;
	}
	return (max_len);
}

void	get_right_padding(t_len **len, t_dir *buf, char options[6])
{
	(*len)->max_sz = display_total_blocks(buf, options);
	(*len)->max_ln = get_links_len(buf, options);
	(*len)->max_ow = get_max_owner_len(buf, options);
	(*len)->max_gr = get_max_group_len(buf, options);
}
