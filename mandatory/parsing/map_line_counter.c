/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:43:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/14 18:17:53 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// counting lines in map and check if there is an empty line
void	map_line_counter(char *file, t_pars *pars)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	pars->col = ft_strlen(line);
	map_line_counter_norm(line, pars, fd);
	pars->row = pars->map_index;
	pars->map = (char **)malloc(sizeof(char *) * (pars->row + 1));
	if (!pars->map)
		return ;
	close(fd);
	pars->map[0] = NULL;
}

// setting textures path
void	north(t_pars *pars, char *str)
{
	char	**s;

	if (!pars->north)
	{
		s = my_split(str);
		if (!s || !s[1] || s[2])
			ft_error("North path not exist\n");
		pars->north = ft_strdup(s[1]);
		free_all(s);
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
		pars->south = ft_strdup(s[1]);
		free_all(s);
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
		pars->west = ft_strdup(s[1]);
		free_all(s);
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
		pars->east = ft_strdup(s[1]);
		free_all(s);
	}
	else
		ft_error("East path is already set\n");
}
