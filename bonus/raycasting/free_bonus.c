/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:28:49 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 17:34:08 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static void	destroy_textures(t_data *data)
{
	mlx_destroy_image(data->mlx, data->text.north.img);
	mlx_destroy_image(data->mlx, data->text.west.img);
	mlx_destroy_image(data->mlx, data->text.south.img);
	mlx_destroy_image(data->mlx, data->text.east.img);
}

static void	destroy_doors(t_data *data)
{
	mlx_destroy_image(data->mlx, data->text.door.img);
	mlx_destroy_image(data->mlx, data->text.door2.img);
	mlx_destroy_image(data->mlx, data->text.door3.img);
}

static void	destroy_gun_frames(t_data *data)
{
	mlx_destroy_image(data->mlx, data->frames.f1);
	mlx_destroy_image(data->mlx, data->frames.f2);
	mlx_destroy_image(data->mlx, data->frames.f3);
	mlx_destroy_image(data->mlx, data->frames.f4);
	mlx_destroy_image(data->mlx, data->frames.f5);
	mlx_destroy_image(data->mlx, data->frames.f6);
	mlx_destroy_image(data->mlx, data->frames.f7);
	mlx_destroy_image(data->mlx, data->frames.f8);
	mlx_destroy_image(data->mlx, data->frames.f9);
	mlx_destroy_image(data->mlx, data->frames.f10);
	mlx_destroy_image(data->mlx, data->frames.f11);
	mlx_destroy_image(data->mlx, data->frames.f12);
	mlx_destroy_image(data->mlx, data->frames.f13);
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
		destroy_gun_frames(data);
		destroy_doors(data);
		free(data->mlx);
	}
	free_parsing(data->pars);
	free(data);
	exit(status);
}
