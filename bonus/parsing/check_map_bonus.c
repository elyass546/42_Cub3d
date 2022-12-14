/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:27:46 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/14 16:51:36 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	door_not_in_edges(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if ((map[i][j] == 'D') && (i == 0 || j == 0 || map[i + 1] == NULL
			|| check_line1(map[i + 1], j) || check_line1(map[i - 1], j)
			|| is_space(map[i - 1][j]) || is_space(map[i + 1][j])
			|| is_space(map[i][j - 1]) || is_space(map[i][j + 1])))
			ft_error("Please check your door!\n");
		j++;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	colors_checker(t_pars *pars, char *line)
{
	char	**s;

	s = my_split(line);
	if (!s || !s[1] || s[2])
		ft_error("Error in colors settings\n");
	if ((ft_strncmp("F ", line, 2) == 0) && pars->floor == -1)
		pars->floor = set_colors(s[1]);
	else if ((ft_strncmp("C ", line, 2) == 0) && pars->ceilling == -1)
		pars->ceilling = set_colors(s[1]);
	else
		ft_error("Textures settings doesn't correct\n");
	free_all(s);
}

int	check_line_helper(char *line, t_pars *pars)
{
	const char	*check[] = {"NO ", "SO ", "WE ", "EA "};
	static void	(*funcptr[5])(t_pars *, char *) = {north, south, west, east};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(check[i], line, 3) == 0)
		{
			funcptr[i](pars, line);
			return (1);
		}
		i++;
	}
	return (0);
}

// check wall in map's left
int	is_map(char *line, t_pars *pars)
{
	int	i;

	i = 0;
	(void) pars;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}
