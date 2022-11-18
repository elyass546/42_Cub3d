/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:43:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/18 22:07:27 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	find_player_pos(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	pars->col = ft_strlen(pars->map[0]);
	while (i < pars->row)
	{
		if (ft_strlen(pars->map[i]) > pars->col)
			pars->col = ft_strlen(pars->map[i]);
		player_pos(pars->map[i], pars);
		j = 0;
		while (pars->map[i][j])
		{
			if (is_playerchar(pars->map[i][j]))
			{
				pars->player_y = i;
				pars->player_x = j;				
			}
			else if (!is_mapchar(pars->map[i][j], pars))
				ft_error("Element zayd a chamchoun\n");
			j++;
		}
		i++;
	}
	if (!pars->player_pos)
		ft_error("Player not found\n");
}

void	map_storing(char *file, t_pars *pars)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line || !pars->row)
		ft_error("Empty map\n");
	pars->map = malloc(sizeof(char *) * (pars->row + 1));
	if (!pars->map)
		return ;
	while (i < pars->map_start_index - 1)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < pars->row)
	{
		if (line[0] == '\0')
			pars->map[i] = ft_strdup("");
		else
			pars->map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	pars->map[i] = NULL;
	// find_player_pos(pars);
}

void	north(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->north)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
		{
			if (s)
				free_all(s);
			ft_error("path not exist\n");
		}
		pars->north = ft_strdup(str);
		pars->id++;
		pars->map_start_index++;
	}
	else
		ft_error("This path is already set\n");
}

void	south(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->south)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
		{
			if (s)
				free_all(s);
			ft_error("path not exist\n");
		}
		pars->south = ft_strdup(str);
		pars->id++;
		pars->map_start_index++;
	}
	else
		ft_error("This path is already set\n");
}

void	west(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->west)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
		{
			if (s)
				free_all(s);
			ft_error("path not exist\n");
		}
		pars->west = ft_strdup(str);
		pars->id++;
		pars->map_start_index++;
	}
	else
		ft_error("This path is already set\n");
}

void	east(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->east)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
		{
			if (s)
				free_all(s);
			ft_error("path not exist\n");
		}
		pars->east = ft_strdup(str);
		pars->id++;
		pars->map_start_index++;
	}
	else
		ft_error("This path is already set\n");
}
