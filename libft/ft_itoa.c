/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:47:50 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/04 14:56:28 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_len(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_reverse(char *str)
{
	int		i;
	int		len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

static unsigned int	ft_absolute_value(int n)
{
	unsigned int	number;

	if (n < 0)
		number = n * -1;
	else
		number = n;
	return (number);
}

static char	*process(char *str, int n)
{
	int	i;
	int	ngtv;

	i = 0;
	ngtv = 0;
	if (n < 0)
		ngtv = 1;
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = (ft_absolute_value(n) % 10) + '0';
		n = n / 10;
	}
	if (ngtv)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_reverse(str);
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = calculate_len(n);
	if (n < 0)
		len++;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = process(str, n);
	return (str);
}
