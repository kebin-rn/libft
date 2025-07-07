/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:41:58 by rnihei            #+#    #+#             */
/*   Updated: 2025/04/25 20:43:29 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*last_occur;
	unsigned char	uc;

	uc = (unsigned char)c;
	last_occur = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
		{
			last_occur = (char *)(s + i);
		}
		i = i + 1;
	}
	if (uc == '\0')
	{
		return ((char *)(s + i));
	}
	return (last_occur);
}
