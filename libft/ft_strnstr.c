/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 15:56:13 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/26 08:58:26 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!(*s2))
		return ((char*)s1);
	while (*s1 && n--)
	{
		if (*s1 == s2[0])
		{
			i = 1;
			while (n-- && s1[i] && s2[i] && s1[i] == s2[i])
				++i;
			if (i == ft_strlen(s2))
				return ((char*)s1);
			n += i;
		}
		++s1;
	}
	return (NULL);
}
