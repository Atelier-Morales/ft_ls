/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 19:07:36 by fmorales          #+#    #+#             */
/*   Updated: 2016/11/19 19:07:40 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				sort_strcmp(void *s1_, void *s2_, int reverse)
{
	char		*s1;
	char		*s2;

	s1 = OS_MODE == 0 ? lower_str(s1_) : s1_;
	s2 = OS_MODE == 0 ? lower_str(s2_) : s2_;
	if (reverse == 1)
		return (ft_strcmp(s1, s2) < 0);
	return (ft_strcmp(s1, s2) > 0);
}

int				sort_time(t_dir *tmp_next, t_dir *tmp, int reverse)
{
	char		*s1;
	char		*s2;

	s1 = OS_MODE == 0 ? lower_str(tmp_next->name) : tmp_next->name;
	s2 = OS_MODE == 0 ? lower_str(tmp->name) : tmp->name;
	if (ft_strcmp(tmp_next->timestamp, tmp->timestamp) != 0)
	{
		if (reverse == 1)
			return (ft_strcmp(tmp_next->timestamp, tmp->timestamp) < 0);
		return (ft_strcmp(tmp_next->timestamp, tmp->timestamp) > 0);
	}
	if (reverse == 1)
		return (ft_strcmp(s1, s2) > 0);
	return (ft_strcmp(s1, s2) < 0);
}
