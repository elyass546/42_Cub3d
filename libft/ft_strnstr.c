/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:13:55 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/03 13:09:11 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		found;

	if (!*needle)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			found = 1;
			while (needle[j])
			{
				if (haystack[i + j] != needle[j])
					found = 0;
				j++;
			}
			if (found && i + j <= len)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
