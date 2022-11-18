/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:11 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/18 17:26:55 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_line1(char *str, int x)
{
	if (x > ft_strlen(str))
		return (1);
	return (0);
}

void	is_surrounded_by_walls(t_pars *data)
{
	char	**map;
	size_t	i;
	size_t	j;

	i = 0;
	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (i == 0 || j == 0
				|| map[i][j + 1] == '\0' || map[i + 1] == NULL
				|| j >= data->col - 1 || i >= data->row - 1
				|| check_line1(map[i + 1], j) || check_line1(map[i - 1], j)
				|| is_space(map[i - 1][j])|| is_space(map[i + 1][j])
				|| is_space(map[i][j - 1])|| is_space(map[i][j + 1])))
				ft_error("Unclosed map!\n");
			j++;
		}
		i++;
	}
}