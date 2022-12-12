/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:58:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/12 17:17:45 by mkorchi          ###   ########.fr       */
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
