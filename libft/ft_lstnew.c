/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:45:03 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/26 08:51:45 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list			*ft_lstnew(const void *data, size_t data_sz)
{
	t_list		*new;

	if ((new = (t_list*)malloc(sizeof(*new))) == NULL)
		return (NULL);
	new->content = (void*)data;
	new->content_size = data ? data_sz : 0;
	new->next = NULL;
	return (new);
}
