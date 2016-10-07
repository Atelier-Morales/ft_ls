/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:59:22 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:18:55 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *dst, int c, size_t n)
{
	char	*d;

	if (n)
	{
		d = (char*)dst;
		while (n--)
			*(d++) = (char)c;
	}
	return (dst);
}
