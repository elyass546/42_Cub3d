/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:10:30 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/12 15:59:17 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	init_gun_animation(t_data *data)
{
	data->frames.f1 = get_img(data, "./sprites//machine_gun/mc1.xpm");
	data->frames.f2 = get_img(data, "./sprites//machine_gun/mc2.xpm");
	data->frames.f3 = get_img(data, "./sprites//machine_gun/mc3.xpm");
	data->frames.f4 = get_img(data, "./sprites//machine_gun/mc4.xpm");
	data->frames.f5 = get_img(data, "./sprites//machine_gun/mc5.xpm");
	data->frames.f6 = get_img(data, "./sprites//machine_gun/mc6.xpm");
	data->frames.f7 = get_img(data, "./sprites//machine_gun/mc7.xpm");
	data->frames.f8 = get_img(data, "./sprites//machine_gun/mc8.xpm");
	data->frames.f9 = get_img(data, "./sprites//machine_gun/mc9.xpm");
	data->frames.f10 = get_img(data, "./sprites//machine_gun/mc10.xpm");
	data->frames.f11 = get_img(data, "./sprites//machine_gun/mc11.xpm");
	data->frames.f12 = get_img(data, "./sprites//machine_gun/mc12.xpm");
	data->frames.f13 = get_img(data, "./sprites//machine_gun/mc13.xpm");
}

void	init_door_animation(t_data *data)
{
	data->text.door.img = mlx_xpm_file_to_image(data->mlx,
			"./frames/budget_door.xpm",
			&data->frames.x, &data->frames.y);
	data->text.door.addr = mlx_get_data_addr(data->text.door.img,
			&data->text.door.bits_per_pixel,
			&data->text.door.line_length, &data->text.door.endian);
	data->text.door2.img = mlx_xpm_file_to_image(data->mlx,
			"./frames/budget_door2.xpm",
			&data->frames.x, &data->frames.y);
	data->text.door2.addr = mlx_get_data_addr(data->text.door2.img,
			&data->text.door2.bits_per_pixel,
			&data->text.door2.line_length, &data->text.door2.endian);
	data->text.door3.img = mlx_xpm_file_to_image(data->mlx,
			"./frames/budget_door3.xpm",
			&data->frames.x, &data->frames.y);
	data->text.door3.addr = mlx_get_data_addr(data->text.door3.img,
			&data->text.door3.bits_per_pixel,
			&data->text.door3.line_length, &data->text.door3.endian);
}

static int	shoot_with_mouse2(t_data *data, int x, int y)
{
	if (data->i < 35)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f7, x, y);
	else if (data->i < 40)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f8, x, y);
	else if (data->i < 45)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f9, x, y);
	else if (data->i < 50)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f10, x, y);
	else if (data->i < 55)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f11, x, y);
	else if (data->i < 60)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f12, x, y);
	else if (data->i <= 65)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f13, x, y);
}

int	shoot_with_mouse(t_data *data)
{
	int	x;
	int	y;

	x = (WIDTH / 2) - 100;
	y = (HEIGHT / 2) + 30;
	if (data->i < 5)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f1, x, y);
	else if (data->i < 10)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f2, x, y);
	else if (data->i < 15)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f3, x, y);
	else if (data->i < 20)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f4, x, y);
	else if (data->i < 25)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f5, x, y);
	else if (data->i < 30)
		mlx_put_image_to_window(data->mlx, data->win, data->frames.f6, x, y);
	else
		shoot_with_mouse2(data, x, y);
	return (0);
}
