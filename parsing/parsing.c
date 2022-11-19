/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:01 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/19 22:36:05 by ie-laabb         ###   ########.fr       */
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

static void	init(t_pars *pars)
{
	pars->ceilling = 0;
	pars->floor = 0;
	pars->id = 0;
	pars->col = 0;
	pars->row = 0;
	pars->map_start_index = 0;
	pars->map_end_index = 0;
	pars->player_pos = 0;
	pars->north = NULL;
	pars->south = NULL;
	pars->east = NULL;
	pars->west = NULL;
	pars->map = NULL;
}

void	parsing_helper(char *line, t_pars *pars, int fd, char *file)
{
	map_storing(file, pars);
	while (line)
	{
		check_line(line, pars);
		free(line);
		line = get_next_line(fd);
	}
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
	parsing_helper(line, pars, fd, file);
	close(fd);
	// for (int i = 0; pars->map[i]; i++)
	// 	printf("%s\n", pars->map[i]);
	// printf("pars->id : %d\npars->map_index : %d\n", pars->id, pars->map_start_index);
	// if (pars->id == 6)
	// 	map_storing(file, pars);
	return (pars);
}
