/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorting_rules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:07:44 by fmorales          #+#    #+#             */
/*   Updated: 2016/12/03 16:09:10 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			set_sorting_rules(t_dir **directory, char options[6])
{
	if (ft_strchr(options, 'r') == NULL \
			&& ft_strchr(options, 't') == NULL \
			&& (*directory)->next != NULL)
		sort_list(*directory, 1);
	else if (ft_strchr(options, 'r') != NULL \
			&& ft_strchr(options, 't') == NULL \
			&& (*directory)->next != NULL)
		sort_list(*directory, 0);
	else if (ft_strchr(options, 'r') == NULL \
			&& ft_strchr(options, 't') != NULL \
			&& (*directory)->next != NULL)
		sort_list_time(*directory, 0);
	else if (ft_strchr(options, 'r') != NULL \
			&& ft_strchr(options, 't') != NULL \
			&& (*directory)->next != NULL)
		sort_list_time(*directory, 1);
}
