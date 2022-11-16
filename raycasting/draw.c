/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:48 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/16 18:16:55 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

t_point		new_point(int x, int y)
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
		new_point(data->player.pos.x, data->player.pos.y),
			0x00FF0000, data->player.height);
	px = data->player.pos.x + cos(data->player.rotation_angle) * 40; // 40 distance
	py = data->player.pos.y + sin(data->player.rotation_angle) * 40;
	dda(&data->img, new_point(data->player.pos.x + data->player.height / 2, data->player.pos.y + data->player.height / 2), new_point(px,py), 0x00FF0000);
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

void	draw_walls(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (data->pars->map[i]) // map[i]
	{
		j = 0;
		while (data->pars->map[i][j]) //map[i][j]
		{
			if (data->pars->map[i][j] == '1')
				color = 0x00FFFFFF;
			else if (data->pars->map[i][j] == ' ')
				color = 0x00808080;
			else
				color = 0x00000000;
			draw_square(&data->img,
				new_point(j * TILE_SIZE, i * TILE_SIZE),
					color, TILE_SIZE);
			// printf("%c ", data->pars->map[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
}

void	dda(t_img *img, t_point a, t_point b, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	xInc;
	float	yInc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xInc = dx / (float) steps;
	yInc = dy / (float) steps;
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