/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:48 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/04 12:39:17 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting_bonus.h"

t_point		new_point(int x, int y)
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

	double grid_x = data->player.pos.x / TILE_SIZE;
	double grid_y = data->player.pos.y / TILE_SIZE;
	
	draw_square(&data->img,
		new_point(grid_x * SCALE, grid_y * SCALE),
			0x00FF0000,
				2);
	px = (grid_x * SCALE) + cos(data->player.rotation_angle) * 10;
	py = (grid_y * SCALE) + sin(data->player.rotation_angle) * 10;
	dda(&data->img,
		new_point(grid_x * SCALE, grid_y * SCALE),
			new_point(px, py),
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

void	draw_minimap(t_data *data)
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
			else if (data->pars->map[i][j] == 'D')
				color = 0x00FFD700;
			else if (data->pars->map[i][j] == 'O')
				color = 0x00808080;
			else if (data->pars->map[i][j] == ' ')
				color = 0x00808080;
			else
				color = 0x00000000;
			draw_square(&data->img,
				new_point(j * SCALE, i * SCALE),
					color, SCALE);
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
	double	xInc;
	double	yInc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xInc = dx / (double) steps;
	yInc = dy / (double) steps;
	int i = 0;
	while (i < steps)
	{
		// if (round(a.y) < 0 || round(a.y) > data->y)
		// 	return ;
		// if (round(a.x) < 0 || round(a.x) > data->x)
		// 	return ;
		my_mlx_pixel_put(img, round(a.x), round(a.y), color);
		a.x += xInc;
		a.y += yInc;
		i++;
	}
}