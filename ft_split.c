/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:01:29 by haelee            #+#    #+#             */
/*   Updated: 2020/11/28 22:05:38 by haelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nums_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nums_word;

	i = 0;
	nums_word = 0;
	while (s[i])
	{
		if (s[i] != c)
			nums_word++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (nums_word);
}

static int			ft_getlen_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static int			ft_getidx(char const *s, char c, char *result)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	return (i);
}

static char			**ft_free_all(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (ft_nums_word(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_nums_word(s, c))
	{
		if (s[j])
		{
			result[i] =
				(char *)malloc(sizeof(char) * (ft_getlen_word(&s[j], c) + 1));
			if (result[i] == NULL)
				return (ft_free_all(result));
			j += ft_getidx(&s[j], c, result[i]);
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
