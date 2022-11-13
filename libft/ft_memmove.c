/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:43:37 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/12 09:38:24 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = -1;
	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (len == 0)
		return (dst);
	if (dst < src)
	{
		while (++i < len)
			d[i] = s[i];
	}
	else if (dst > src)
	{
		while (++i < len)
			d[len - i - 1] = s[len - i - 1];
	}
	return (dst);
}
