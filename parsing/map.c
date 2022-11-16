/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:45:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/16 19:33:10 by ie-laabb         ###   ########.fr       */
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

void	colors_checker(char *line, t_pars *pars)
{
	char		**s;

	s = my_split(line);
	if (!s[1] || !s)
		ft_error("path not exist\n");
	if ((ft_strncmp("F", s[0], 1) == 0) && !pars->floor)
	{
		pars->floor = set_colors(s[1]);
		pars->id++;
		pars->map_index++;
	}
	else if ((ft_strncmp("C", s[0], 1) == 0) && !pars->ceilling)
	{
		pars->ceilling = set_colors(s[1]);
		pars->id++;
		pars->map_index++;
	}
	else
		ft_error("Textures settings doen't correct\n");
	free_all(s);
}

void	check_line(char *line, t_pars *pars)
{
	int			i;
	const char	*check[] = {"NO ", "SO ", "WE ", "EA "};
	void	(*funcptr[4])(t_pars *, char *) = {north, south, west, east};

	i = 0;
	if (line[0] == '\0' || !line)
	{
		pars->map_index++;
		return ;
	}
	while (i < 4)
	{
		if (ft_strncmp(check[i], line, 3) == 0)
		{
			funcptr[i](pars, line);
			return ;
		}
		i++;
	}
	colors_checker(line, pars);
}

void	player_pos(char *line, t_pars *pars)
{
	int i;

	i = 0;
	while (i < ft_strlen(line) - 1)
	{
		if (is_playerchar(line[i]) && !pars->player_pos)
		{
			pars->player_pos = line[i];
			return ;
		}
		i++;
	}
	ft_error("Duplicat player position\n");
}
