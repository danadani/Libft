/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <haelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:04:48 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 18:04:50 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t		numlen;
	size_t		sign;
	char		*result;
	long long	num;

	numlen = get_num_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (numlen + 1))))
		return (NULL);
	result[numlen] = '\0';
	sign = 0;
	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		result[0] = '-';
		sign = 1;
	}
	while (numlen-- > sign)
	{
		result[numlen] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
