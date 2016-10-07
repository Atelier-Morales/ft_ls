/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:21:54 by fmorales          #+#    #+#             */
/*   Updated: 2013/11/28 19:01:48 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	*res;

	res = ft_itoa(n);
	ft_putstr_fd(res, fd);
	free(res);
}
