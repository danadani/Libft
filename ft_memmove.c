/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <haelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:07:19 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 20:57:47 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	i = 0;
	if (dst < src)
		while (len > i)
		{
			dest[i] = sorc[i];
			i++;
		}
	else
		while (len > 0)
		{
			dest[len - 1] = sorc[len - 1];
			len--;
		}
	return (dst);
}
