/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:47:11 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/26 23:01:14 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

static int	calculate_len(char const *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (is_space(s[i]) && !is_space(s[i + 1]))
			len++;
		i++;
	}
	if (is_space(s[i - 1]))
		len--;
	if (!is_space(s[0]))
		len++;
	return (len);
}

static char	*getstring(char const *str)
{
	int		i;
	char	*mystr;

	i = 0;
	while (!is_space(str[i]) && str[i] != '\0')
		i++;
	mystr = (char *) malloc(sizeof(char) * (i + 1));
	if (!mystr)
		return (NULL);
	i = 0;
	while (!is_space(str[i]) && str[i] != '\0')
	{
		mystr[i] = str[i];
		i++;
	}
	mystr[i] = '\0';
	return (mystr);
}

static int	process(char **strs, char const *s)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (s[i])
	{
		if ((!is_space(s[0]) && i == 0) || (i > 0 && !is_space(s[i])
				&& is_space(s[i - 1])))
		{
			str = getstring(s + i);
			if (str == NULL)
				return (0);
			strs[k++] = str;
		}
		i++;
	}
	strs[k] = 0;
	return (1);
}

char	**my_split(char const *s)
{
	char	**strs;
	int		len;
	int		res;

	res = 0;
	if (!s)
		return (NULL);
	len = calculate_len(s);
	strs = (char **) malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	res = process(strs, s);
	if (res)
		return (strs);
	free_all(strs);
	strs = NULL;
	return (strs);
}
