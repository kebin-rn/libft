/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:33:08 by rnihei            #+#    #+#             */
/*   Updated: 2025/04/27 15:33:12 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_substr_c(const char **s, char c)
{
	char	*word;
	size_t	len;
	size_t	wlen;

	len = ft_wordlen(*s, c);
	wlen = len;
	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (len > 0)
	{
		len--;
		word[len] = (*s)[len];
	}
	word[wlen] = '\0';
	*s += wlen;
	return (word);
}

static int	ft_freeall(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;
	size_t	i;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		res[i] = ft_substr_c(&s, c);
		if (res[i] == NULL && ft_freeall(res, i))
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
