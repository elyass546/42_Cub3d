/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:02:12 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/08 13:43:45 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	mychar;

	i = 0;
	mychar = (char) c;
	while (s[i])
	{
		if (s[i] == mychar)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == mychar)
		return ((char *) s + i);
	return (NULL);
}
