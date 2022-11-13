/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:22:18 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/08 13:45:15 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	int		last;
	char	mychar;

	n = 0;
	last = -1;
	mychar = (char) c;
	while (s[n])
	{
		if (s[n] == mychar)
			last = n;
		n++;
	}
	if (s[n] == mychar)
		return ((char *) s + n);
	if (last == -1)
		return (NULL);
	else
		return ((char *) s + last);
}
