/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:01 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/14 18:21:02 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	set_colors(char *str)
{
	char	**s;
	int		r;
	int		g;
	int		b;

	s = ft_split(str, ',');
	if (!s[1] || !s[2] || !s)
		ft_error("Color not set\n");
	r = ft_atoi(s[0]);
	g = ft_atoi(s[1]);
	b = ft_atoi(s[2]);
	free_all(s);
	if ((r > 255 || r < 0) || (g > 255 || g < 0)
		|| (b > 255 || b < 0))
			ft_error("Color setting is not correct\n");
	return (r << 8 | g << 4 | b);
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
	while (line && i < pars->row)
	{
		if (line[0] == '1')
		{
			pars->map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	pars->map[i] = NULL;
}

void	check_line(char *line, t_pars *pars)
{
	char **s;

	if (line[0] == '\0' || !line)
		return ;
	s = my_split(line);
	if (!s[1] || !s)
		ft_error("path not exist\n");
	if ((ft_strncmp("NO", s[0], 2) == 0) && !pars->north)
	{
		pars->north = ft_strdup(s[1]);
		pars->id++;
	}
	else if ((ft_strncmp("SO", s[0], 2) == 0) && !pars->south)
	{
		pars->south = ft_strdup(s[1]);
		pars->id++;
	}
	else if ((ft_strncmp("WE", s[0], 2) == 0) && !pars->west)
	{
		pars->west = ft_strdup(s[1]);
		pars->id++;
	}
	else if ((ft_strncmp("EA", s[0], 2) == 0) && !pars->east)
	{
		pars->east = ft_strdup(s[1]);
		pars->id++;
	}
	else if ((ft_strncmp("F", s[0], 1) == 0) && !pars->floor)
	{
		pars->floor = set_colors(s[1]);
		pars->id++;
	}
	else if ((ft_strncmp("C", s[0], 1) == 0) && !pars->ceilling)
	{
		pars->ceilling = set_colors(s[1]);
		pars->id++;
	}
	else
		ft_error("Textures settings doen't correct\n");
	free_all(s);
}

static void	init(t_pars *pars)
{
	pars->ceilling = 0;
	pars->floor = 0;
	pars->id = 0;
	pars->col = 0;
	pars->row = 0;
	pars->north = NULL;
	pars->south = NULL;
	pars->east = NULL;
	pars->west = NULL;
	pars->map = NULL;
}

void	parsing(char *file)
{
	int		fd;
	char	*line;
	t_pars	pars;

	init(&pars);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	while (line)
	{
		if (pars.id < 6)
			check_line(line, &pars);
		else
		{
			if (line[0] == '1')
				pars.row++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (pars.id == 6)
		map_storing(file, &pars);
	int i = 0;
	while (i < pars.row)
		printf("%s\n", pars.map[i++]);
}
