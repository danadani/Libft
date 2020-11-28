/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:54:45 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 18:55:14 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	change_char(int n, int fd)
{
	if (n >= 10)
	{
		change_char(n / 10, fd);
		change_char(n % 10, fd);
	}
	else if (n >= 0)
	{
		n += '0';
		write(fd, &n, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	change_char(n, fd);
}
