/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:58:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/14 18:15:17 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	opening_textures_path(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static void	free_error_(t_pars *pars)
{
	free_parsing(pars);
	ft_error("File doesn't exist!\n");
}

void	check_textures_path(t_pars *pars)
{
	if (!opening_textures_path(pars->north))
		free_error_(pars);
	if (!opening_textures_path(pars->west))
		free_error_(pars);
	if (!opening_textures_path(pars->east))
		free_error_(pars);
	if (!opening_textures_path(pars->south))
		free_error_(pars);
}

void	map_line_counter_norm(char *line, t_pars *pars, int fd)
{
	while (line)
	{
		if (ft_strlen(line) > pars->col)
			pars->col = ft_strlen(line);
		if (is_map(line) || line[0] == '1')
		{
			if (pars->flag == -1)
				pars->flag = 0;
			pars->map_index++;
		}
		else if (!pars->flag)
			pars->flag = 1;
		if ((is_map(line) || line[0] == '1') && pars->flag)
		{
			if (line)
				free(line);
			ft_error("Empty line inside map!\n");
		}
		free(line);
		line = get_next_line(fd);
	}
}
