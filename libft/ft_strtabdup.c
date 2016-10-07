/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 05:02:09 by fmorales          #+#    #+#             */
/*   Updated: 2014/01/01 06:25:18 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strtabdup(char **array)
{
	int		i;
	int		j;
	char	**ret;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		++i;
	if (!(ret = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	j = -1;
	while (++j < i)
		ret[j] = ft_strdup(array[j]);
	ret[j] = NULL;
	return (ret);
}
