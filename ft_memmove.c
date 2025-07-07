/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnihei <rnihei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:16:53 by rnihei            #+#    #+#             */
/*   Updated: 2025/04/25 19:17:15 by rnihei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	d_ptr = (unsigned char *)dst;
	s_ptr = (const unsigned char *)src;
	if (d_ptr == s_ptr || n == 0)
		return (dst);
	if (d_ptr < s_ptr)
	{
		while (n--)
			*d_ptr++ = *s_ptr++;
	}
	else
	{
		d_ptr += n;
		s_ptr += n;
		while (n--)
			*(--d_ptr) = *(--s_ptr);
	}
	return (dst);
}
