/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:01 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/16 15:21:52 by ie-laabb         ###   ########.fr       */
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
	while(i < pars->map_index)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	while (i < pars->row - 1)
		pars->map[i++] = get_next_line(fd);
	pars->map[i] = NULL;
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

void	check_line(char *line, t_pars *pars)
{
	int			i;
	char		**s;
	const char	*check[] = {"NO", "SO", "WE", "EA"};
	void		(*funcptr[4])(t_pars *, char *) =
		{north, south, west, east};
	i = 0;
	if (line[0] == '\0' || !line)
	{
		pars->map_index++;
		return ;
	}
	s = my_split(line);
	if (!s[1] || !s)
		ft_error("path not exist\n");
	while (i < 4)
	{
		if (ft_strncmp(check[i], line, 2) == 0)
		{
			funcptr[i](pars, line);
			return ;
		}
		i++;
	}
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

static void	init(t_pars *pars)
{
	pars->ceilling = 0;
	pars->floor = 0;
	pars->id = 0;
	pars->col = 0;
	pars->row = 0;
	pars->map_index = 0;
	pars->north = NULL;
	pars->south = NULL;
	pars->east = NULL;
	pars->west = NULL;
	pars->map = NULL;
}

t_pars	*parsing(char *file)
{
	int		fd;
	char	*line;
	t_pars	*pars;

	pars = malloc(sizeof(t_pars));
	init(pars);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	while (line)
	{
		if (pars->id < 6)
			check_line(line, pars);
		else
		{
			if (is_mapchar(line[0], pars))
				pars->row++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (pars->id == 6)
		map_storing(file, pars);
	return (pars);
}
