/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 15:55:54 by fmorales          #+#    #+#             */
/*   Updated: 2013/12/26 08:59:03 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strtrim(const char *s)
{
	char		*ret;
	int			len;

	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		++s;
	len = ft_strlen(s) - 1;
	while (len >= 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		--len;
	if ((ret = ft_strsub(s, 0, len + 1)) == NULL)
		return (NULL);
	return (ret);
}
