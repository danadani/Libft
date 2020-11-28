/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <haelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:09:35 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 19:48:30 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;
	char	letter;

	len = ft_strlen(s);
	str = (char *)s;
	letter = (char)c;
	while (len > 0)
	{
		if (str[len] == letter)
			return (str + len);
		len--;
	}
	if (str[len] == letter)
		return (str);
	return (0);
}
