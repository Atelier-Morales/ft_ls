/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:38:28 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:20:27 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*ss;

	ss = (char*)s;
	while (n--)
		if (*(ss++) == (char)c)
			return ((void*)(ss - 1));
	return (NULL);
}
