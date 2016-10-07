/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:39:49 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/26 15:01:35 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*ret;

	if ((ret = (char*)malloc(size)) == NULL)
		return (NULL);
	while (size-- > 0)
		ret[size] = 0;
	return ((void*)ret);
}
