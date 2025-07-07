/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:34:13 by rnihei            #+#    #+#             */
/*   Updated: 2025/04/27 15:34:16 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nlen(long n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nl;
	int		len;

	nl = n;
	if (nl < 0)
		nl = -nl;
	len = ft_nlen(nl);
	if (n < 0)
		len++;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (nl % 10);
		nl /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
