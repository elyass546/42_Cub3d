/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:43:55 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/21 15:10:30 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	while (line)
	{
		if (ft_strlen(line) > pars->col)
			pars->col = ft_strlen(line);
		if (is_map(line, pars) || line[0] == '1')
			pars->map_index++;
		free(line);
		line = get_next_line(fd);
	}
	pars->row = pars->map_index;
	pars->map = (char **)malloc(sizeof(char *) * (pars->row + 1));
	if (!pars->map)
		return ;//check if I can return (void)
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
