/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:11:44 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:19:14 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*d;
	const char	*s;

	if (n)
	{
		d = (char*)s1;
		s = (const char*)s2;
		while (n--)
			*(d++) = *(s++);
	}
	return (s1);
}
