/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:53:56 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 17:09:46 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	destroy_textures(t_data *data)
{
	mlx_destroy_image(data->mlx, data->text.north.img);
	mlx_destroy_image(data->mlx, data->text.west.img);
	mlx_destroy_image(data->mlx, data->text.south.img);
	mlx_destroy_image(data->mlx, data->text.east.img);
}

void	free_exit(t_data *data, int status)
{
	if (status)
		ft_putstr_fd("ERROR\n", 2);
	if (data->mlx)
	{
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		destroy_textures(data);
		free(data->mlx);
	}
	free_parsing(data->pars);
	free(data);
	exit(status);
}
