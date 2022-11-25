/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:10:30 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/25 16:03:27 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	animate(t_data *data)
{
	if (data->i < 5)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f1, 75, 0);
	else if (data->i < 10)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f2, 75, 0);
	else if (data->i < 15)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f3, 75, 0);
	else if (data->i < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f4, 75, 0);
	else if (data->i < 25)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f5, 75, 0);
	else if (data->i < 30)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f6, 75, 0);
	else if (data->i < 35)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f7, 75, 0);
	else if (data->i < 40)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f8, 75, 0);
	else if (data->i < 45)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f9, 75, 0);
	else if (data->i < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f10, 75, 0);
	else if (data->i < 55)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f11, 75, 0);
	else if (data->i < 60)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f12, 75, 0);
}

void	update_and_animate(t_data *data)
{
	// update_screen(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	animate(data);
}

int	animation(t_data *data)
{
	update_and_animate(data);
	// update_screen(vars);
	if (data->i == 60)
		data->i = 0;
	data->i++;
	return (0);
}