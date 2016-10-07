/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:07:27 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 09:44:17 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(const char *s1, const char *s2)
{
	int			i;
	char		*ret;

	if (!s1 || !s2)
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *(s1++);
	while (*s2)
		ret[i++] = *(s2++);
	ret[i] = '\0';
	return (ret);
}
