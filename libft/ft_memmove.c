/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:39:51 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/26 08:53:02 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*src;

	if (n)
	{
		src = ft_memalloc(n);
		ft_memcpy(src, s2, n);
		ft_memcpy(s1, src, n);
		free(src);
	}
	return (s1);
}
