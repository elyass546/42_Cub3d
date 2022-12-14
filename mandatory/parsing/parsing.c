/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:01 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/14 21:58:06 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// check comma's number
void	check_comma_in_str(char *line)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ',')
			ft_error("Number of commas is incorrect!\n");
		else if (line[i] == ',')
			counter++;
		i++;
	}
	if (counter != 2 || (line[i - 1] == ',' && !line[i]))
		ft_error("Wrong input in the color section\n");
}

//setting colors
int	set_colors(char *str)
{
	char	**s;
	int		r;
	int		g;
	int		b;

	check_comma_in_str(str);
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
	return (r << 16 | g << 8 | b);
}

// init t_pars variables
static void	init(t_pars *pars)
{
	pars->ceilling = -1;
	pars->floor = -1;
	pars->flag = -1;
	pars->col = 0;
	pars->row = 0;
	pars->texture_checker = 0;
	pars->map_index = 0;
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
	map_line_counter(file, pars);
	while (line)
	{
		check_line(line, pars);
		free(line);
		line = get_next_line(fd);
	}
	check_textures_path(pars);
}

// main function
t_pars	*parsing(char *file)
{
	int		fd;
	char	*line;
	t_pars	*pars;

	pars = malloc(sizeof(t_pars));
	if (!pars)
		ft_error("Error\n");
	init(pars);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exist\n");
	line = get_next_line(fd);
	if (!line)
		ft_error("Empty map\n");
	parsing_helper(line, pars, fd, file);
	is_surrounded_by_walls(pars);
	close(fd);
	return (pars);
}
