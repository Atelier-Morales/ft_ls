/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:22:37 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/01 19:30:35 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		sign;

	if (!str)
		return (0);
	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\n'
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? (-(sign)) : (sign);
		str++;
	}
	while (ft_isdigit(*str))
		res = (res * 10) + ((*(str++)) - '0');
	return (res * sign);
}
