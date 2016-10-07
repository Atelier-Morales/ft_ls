/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:57:54 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/29 09:42:33 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*ret;

	if ((ret = (char*)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	++size;
	while (size-- > 0)
		ret[size] = '\0';
	return (ret);
}
