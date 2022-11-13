/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:31:58 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/09 15:33:20 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	mychar;

	i = 0;
	mychar = (unsigned char) c;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == mychar)
			return (str + i);
		i++;
	}
	return (NULL);
}
