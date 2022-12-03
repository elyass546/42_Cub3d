/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:48 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/01 19:42:57 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_point	new_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}

void	draw_player(t_data *data)
{
	float	px;
	float	py;

	draw_square(&data->img,
		new_point(data->player.pos.x, data->player.pos.y), 0x00FF0000, 10);
	px = data->player.pos.x + cos(data->player.rotation_angle) * 40;
	py = data->player.pos.y + sin(data->player.rotation_angle) * 40;
}

void	draw_square(t_img *img, t_point pos, int color, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			my_mlx_pixel_put(img, pos.x + j, pos.y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_walls(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (data->pars->map[i])
	{
		j = 0;
		while (data->pars->map[i][j])
		{
			if (data->pars->map[i][j] == '1')
				color = 0x00FFFFFF;
			else if (data->pars->map[i][j] == ' ')
				color = 0x00808080;
			else
				color = 0x00000000;
			draw_square(&data->img,
				new_point(j * TILE_SIZE, i * TILE_SIZE), color, TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	dda(t_img *img, t_point a, t_point b, int color)
{
	float	dx;
	float	dy;
	float	steps;
	int		i;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(img, round(a.x), round(a.y), color);
		a.x += dx / (float) steps;
		a.y += dy / (float) steps;
		i++;
	}
}
