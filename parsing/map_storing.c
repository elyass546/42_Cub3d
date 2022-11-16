/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:43:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/16 23:10:01 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	find_player_pos(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	while (i < pars->row)
	{
		player_pos(pars->map[i], pars);
		j = 0;
		while (pars->map[i][j])
		{
			if (is_playerchar(pars->map[i][j]))
			{
				pars->player_y = j;
				pars->player_x = i;				
			}
			j++;
		}
		i++;
	}
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
	while (i < pars->map_index - 1)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < pars->row)
		pars->map[i++] = get_next_line(fd);
	pars->map[i] = NULL;
	find_player_pos(pars);
}

void	north(t_pars *pars, char *str)
{
	if (!pars->north)
	{
		pars->north = ft_strdup(str);
		pars->id++;
		pars->map_index++;
	}
}

void	south(t_pars *pars, char *str)
{
	if (!pars->south)
	{
		pars->south = ft_strdup(str);
		pars->id++;
		pars->map_index++;
	}
}

void	west(t_pars *pars, char *str)
{
	if (!pars->west)
	{
		pars->west = ft_strdup(str);
		pars->id++;
		pars->map_index++;
	}
}

void	east(t_pars *pars, char *str)
{
	if (!pars->east)
	{
		pars->east = ft_strdup(str);
		pars->id++;
		pars->map_index++;
	}
}
