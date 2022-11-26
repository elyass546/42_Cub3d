/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:11 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/26 19:45:06 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// check if map name ended with .cub
int	map_name_checker(char *str)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = &str[ft_strlen(str) - 4];
	s2 = ".cub";
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

//finding player position
void	player_pos(char *line, t_pars *pars, int y)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (is_playerchar(line[i]) && !pars->player_pos)
		{
			pars->player_pos = line[i];
			pars->player_x = i;
			pars->player_y = y;
			line[i] = '0';
		}
		else if (is_playerchar(line[i]) && pars->player_pos)
			ft_error("Duplicate player position\n");
		i++;
	}
}

int	check_line1(char *str, int x)
{
	if (x > ft_strlen(str))
		return (1);
	return (0);
}

// check if the map is valid
void	is_surrounded_helper(char **map, t_pars *pars, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if ((map[i][j] == '0' || is_playerchar(map[i][j]))
			&& (i == 0 || j == 0
			|| map[i][j + 1] == '\0' || map[i + 1] == NULL
			|| j >= pars->col - 1 || i >= pars->row - 1
			|| check_line1(map[i + 1], j) || check_line1(map[i - 1], j)
			|| is_space(map[i - 1][j]) || is_space(map[i + 1][j])
			|| is_space(map[i][j - 1]) || is_space(map[i][j + 1])))
			ft_error("Please check your map!\n");
		if (!is_mapchar(map[i][j]))
			ft_error("Wrong element inside your map!\n");
		j++;
	}
}

void	is_surrounded_by_walls(t_pars *pars)
{
	char	**map;
	size_t	i;

	i = 0;
	map = pars->map;
	if (!map[i] || !map[i][0])
		ft_error("Empty map!\n");
	while (map[i])
	{
		is_surrounded_helper(map, pars, i);
		player_pos(map[i], pars, i);
		i++;
	}
	if (!pars->player_pos)
		ft_error("Player not found!\n");
}
