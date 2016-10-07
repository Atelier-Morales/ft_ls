/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:33:37 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/29 19:22:13 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	if (!s2[i] && i < n)
		while (i < n)
		{
			s1[i] = '\0';
			++i;
		}
	return (s1);
}
