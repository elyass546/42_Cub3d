/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:10:30 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/29 20:06:58 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	animate(t_data *data)
{
	/*
	if (data->i < 5)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f1, (WIDTH - 150), 0);
	else if (data->i < 10)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f2, (WIDTH - 150), 0);
	else if (data->i < 15)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f3, (WIDTH - 150), 0);
	else if (data->i < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f4, (WIDTH - 150), 0);
	else if (data->i < 25)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f5, (WIDTH - 150), 0);
	else if (data->i < 30)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f6, (WIDTH - 150), 0);
	else if (data->i < 35)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f7, (WIDTH - 150), 0);
	else if (data->i < 40)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f8, (WIDTH - 150), 0);
	else if (data->i < 45)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f9, (WIDTH - 150), 0);
	else if (data->i < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f10, (WIDTH - 150), 0);
	else if (data->i < 55)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f11, (WIDTH - 150), 0);
	else if (data->i <= 60)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f12, (WIDTH - 150), 0);
	*/
}

int	shoot_with_mouse(t_data *data)
{
	if (data->i < 5)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f1, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 10)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f2, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 15)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f3, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f4, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 25)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f5, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 30)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f6, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 35)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f7, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 40)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f8, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 45)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f9, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f10, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i < 55)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f11, WIDTH / 2, (HEIGHT / 2) + 170);
	else if (data->i <= 60)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f12, WIDTH / 2, (HEIGHT / 2) + 170);
	return (0);
}