/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_path_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:58:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/27 22:39:17 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	opening_textures_path(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	check_textures_path(t_pars *pars)
{
	if (!opening_textures_path(pars->north))
		ft_error("File doesn't exist!\n");
	if (!opening_textures_path(pars->west))
		ft_error("File doesn't exist!\n");
	if (!opening_textures_path(pars->east))
		ft_error("File doesn't exist!\n");
	if (!opening_textures_path(pars->south))
		ft_error("File doesn't exist!\n");
}