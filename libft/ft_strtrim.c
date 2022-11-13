/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:58:51 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/08 13:38:07 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*process(char const *s1, int start, int len)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		count;
	int		start;
	int		end;

	i = 0;
	count = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (contains(s1[i++], set))
		count++;
	start = i - 1;
	i = ft_strlen(s1) - 1;
	while (contains(s1[i--], set))
		count++;
	end = i + 1;
	if (start > end)
		return (ft_strdup(""));
	return (process(s1, start, ft_strlen(s1) - count));
}
