/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:43:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/19 22:37:08 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	find_player_pos(t_pars *pars)
{

}

int	is_map(char *line, t_pars *pars)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	if (!line[0] && pars->map_start_index)
		return (1);
	return (0);
}

void	map_storing(char *file, t_pars *pars)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	while (line)
	{
		if (is_map(line, pars))
			pars->map_start_index++;
		free(line);
		line = get_next_line(fd);
	}
	pars->map = (char **)malloc(sizeof(char *) * (pars->map_start_index + 1));
	if (!pars->map)
		return ; // check this after !
	close(fd);
	pars->map[0] = NULL;
}

void	north(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->north)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
			ft_error("North path not exist\n");
		pars->north = ft_strdup(str);
	}
	else
		ft_error("North path is already set\n");
}

void	south(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->south)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
			ft_error("South path not exist\n");
		pars->south = ft_strdup(str);
	}
	else
		ft_error("South path is already set\n");
}

void	west(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->west)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
			ft_error("West path not exist\n");
		pars->west = ft_strdup(str);
	}
	else
		ft_error("West path is already set\n");
}

void	east(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->east)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
			ft_error("East path not exist\n");
		pars->east = ft_strdup(str);
	}
	else
		ft_error("East path is already set\n");
}
