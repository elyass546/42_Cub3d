/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:20:57 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/26 13:28:07 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_playerchar(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_mapchar(char c)
{
	if ((is_space(c) || c == '1' || c == '0' || c == 'P' || is_playerchar(c)))
		return (1);
	return (0);
}

char	*ft_sjoin(char *s1, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	t_gnl	gnl;

	gnl.read_return = read(fd, &gnl.c, 1);
	gnl.str = ft_strdup("");
	while (gnl.read_return > 0)
	{
		if (gnl.c == '\n')
			break ;
		gnl.temp = gnl.str;
		gnl.str = ft_sjoin(gnl.temp, gnl.c);
		free (gnl.temp);
		gnl.read_return = read(fd, &gnl.c, 1);
	}
	if (gnl.read_return < 0)
	{
		free(gnl.str);
		return (NULL);
	}
	if (gnl.read_return == 0 && !gnl.str[0])
	{
		free(gnl.str);
		return (NULL);
	}
	return (gnl.str);
}
