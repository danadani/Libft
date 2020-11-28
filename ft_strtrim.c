/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <haelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:09:39 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 20:19:07 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s1, char const *set, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_get_end(char const *s1, char const *set, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && ft_strchr(set, s1[len - 1 - i]))
		i++;
	return (len - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		start;
	size_t		end;
	size_t		len;
	size_t		result_len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = ft_get_start(s1, set, len);
	end = ft_get_end(s1, set, len);
	result_len = end - start + 1;
	if (start > end)
		return (ft_strdup(""));
	if (!(result = (char *)malloc(sizeof(char) * (result_len))))
		return (NULL);
	ft_strlcpy(result, s1 + start, result_len);
	return (result);
}
