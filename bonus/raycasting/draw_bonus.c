/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:48 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 14:15:51 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

t_point	new_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	draw_player(t_data *data)
{
	double	px;
	double	py;
	double	grid_x;
	double	grid_y;

	grid_x = data->player.pos.x / TILE_SIZE;
	grid_y = data->player.pos.y / TILE_SIZE;
	draw_square(&data->img,
		new_point(grid_x * SCALE, grid_y * SCALE),
		0x00FF0000, 6);
	px = (grid_x * SCALE) + cos(data->player.rotation_angle) * 15;
	py = (grid_y * SCALE) + sin(data->player.rotation_angle) * 15;
	dda(&data->img,
		new_point(grid_x * SCALE + 3, grid_y * SCALE + 3),
		new_point(px + 3, py + 3),
		0x00FF0000);
}

void	draw_square(t_img *img, t_point pos, int color, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, pos.x + j, pos.y + i, color);
			j++;
		}
		i++;
	}
}

void	dda(t_img *img, t_point a, t_point b, int color)
{
	double		dx;
	double		dy;
	double		steps;
	double		x_inc;
	double		y_inc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / (double) steps;
	y_inc = dy / (double) steps;
	while (steps > 0)
	{
		if (a.y < 0 || a.y > HEIGHT)
			return ;
		if (a.x < 0 || a.x > WIDTH)
			return ;
		my_mlx_pixel_put(img, round(a.x), round(a.y), color);
		a.x += x_inc;
		a.y += y_inc;
		steps--;
	}
}
