/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:13:35 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/26 08:51:03 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnlen(int n)
{
	size_t		ret;

	if (n == 0)
		return (1);
	ret = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		++ret;
		n /= 10;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		len;
	size_t		start;

	len = ft_getnlen(n);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ret[0] = (n < 0) ? '-' : '\0';
	start = (n < 0) ? 1 : 0;
	while (len-- > start)
	{
		ret[len] = (n < 0) ? ('0' - (n % 10)) : ('0' + (n % 10));
		n /= 10;
	}
	return (ret);
}
