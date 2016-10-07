/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:27:04 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:24:42 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (!(*s2))
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 == s2[0])
		{
			i = 0;
			while (s1[i] && s2[i] && s1[i] == s2[i])
				++i;
			if (i == ft_strlen(s2))
				return ((char*)s1);
		}
		++s1;
	}
	return (NULL);
}
