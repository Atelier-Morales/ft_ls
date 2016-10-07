/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:18:26 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/26 15:03:03 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*ret;
	size_t		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if ((ret = ft_strnew(size)) == NULL)
		return (NULL);
	while (size-- > 0)
		ret[size] = f(size, s[size]);
	return (ret);
}
