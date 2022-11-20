/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:45:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/20 14:07:20 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	colors_checker(t_pars *pars, char *line)
{
	char	**s;

	s = my_split(line);
	if (!s[1] || !s)
		ft_error("path not exist\n");
	if ((ft_strncmp("F ", line, 2) == 0) && !pars->floor)
		pars->floor = set_colors(s[1]);
	else if ((ft_strncmp("C ", line, 2) == 0) && !pars->ceilling)
		pars->ceilling = set_colors(s[1]);
	else
		ft_error("Textures settings doesn't correct\n");
	free_all(s);
}

int	check_textutres(t_pars *pars)
{
	if (pars->north && pars->south && pars->east && pars->west)
		return (1);
	return (0);
}

char *skip_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (line + i);
		i++;
	}
	return (line + i);
}

int	check_if_filled(t_pars *pars)
{
	if (check_textutres(pars) && pars->ceilling && pars->floor)
		return (1);
	return (0);
}

void	map_counter(char *line, t_pars *pars)
{
	if (pars->map_end_index < pars->map_start_index)
	{
		pars->map[pars->map_end_index] = ft_strdup(line);
		pars->map_end_index++;	
	}
	if (pars->map_end_index == pars->map_start_index)
		pars->map[pars->map_end_index] = NULL;
}

void	check_line(char *line, t_pars *pars)
{
	int			i;
	const char	*check[] = {"NO ", "SO ", "WE ", "EA "};
	void	(*funcptr[5])(t_pars *, char *) = {north, south, west, east};

	i = 0;
	if (is_space(line[0]) && !pars->map[0])
		line = skip_spaces(line);
	if ((!line[0] || !line) && !pars->map[0])
			return ;
	if (!check_textutres(pars))
	{
		while (i < 4)
		{
			if (ft_strncmp(check[i], line, 3) == 0)
			{
				funcptr[i](pars, line);
				return ;
			}
			i++;
		}
	}
	if (!check_if_filled(pars))
		colors_checker(pars, line);
	else
		map_counter(line , pars);
}

void	player_pos(char *line, t_pars *pars)
{
	int i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (is_playerchar(line[i]) && !pars->player_pos)
			pars->player_pos = line[i];
		else if (is_playerchar(line[i]) && pars->player_pos)
			ft_error("Duplicate player position\n");
		i++;
	}
}
