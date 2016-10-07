/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:37:05 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:20:58 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	if (n)
	{
		ss1 = (unsigned char*)s1;
		ss2 = (unsigned char*)s2;
		while (n--)
			if (*(ss1++) != *(ss2++))
				return (*(ss1 - 1) - *(ss2 - 1));
	}
	return (0);
}
