/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:50 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 14:14:45 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static int	is_out_of_bounds(t_data *data, int offset_x, int offset_y)
{
	if (offset_x < 0 || offset_y < 0
		|| offset_y >= data->pars->row
		|| offset_x >= ft_strlen(data->pars->map[offset_y]))
		return (TRUE);
	return (FALSE);
}

static int	get_color(t_data *data, int offset_x, int offset_y)
{
	if (is_out_of_bounds(data, offset_x, offset_y)
		|| data->pars->map[offset_y][offset_x] == ' '
		|| data->pars->map[offset_y][offset_x] == 'O')
		return (0x000000);
	else if (data->pars->map[offset_y][offset_x] == '1')
		return (0x00FFFFFF);
	else if (data->pars->map[offset_y][offset_x] == 'D')
		return (0x00FFD700);
	else
		return (0x00808080);
}

void	draw_minimap(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_y = y - 4;
	while (i < 9)
	{
		j = 0;
		offset_x = x - 4;
		while (j < 9)
		{
			color = get_color(data, offset_x, offset_y);
			draw_square(&data->img,
				new_point(j * SCALE, i * SCALE),
				color, SCALE);
			j++;
			offset_x++;
		}
		i++;
		offset_y++;
	}
}

void	draw_circle(t_data *data, t_point p, int r, int color)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		my_mlx_pixel_put(&data->img, p.x + x1, p.y + y1, color);
		i += 0.1;
	}
}

void	mini_map(t_data *data)
{
	int		grid_x;
	int		grid_y;
	t_point	center_p;
	float	px;
	float	py;

	grid_x = (int)(data->player.pos.x / TILE_SIZE);
	grid_y = (int)(data->player.pos.y / TILE_SIZE);
	draw_minimap(data, grid_x, grid_y);
	center_p.x = SCALE * 4 + SCALE / 2;
	center_p.y = SCALE * 4 + SCALE / 2;
	draw_circle(data, center_p, 10, 0x702963);
	px = center_p.x + cos(data->player.rotation_angle) * 20;
	py = center_p.y + sin(data->player.rotation_angle) * 20;
	dda(&data->img,
		new_point(center_p.x, center_p.x),
		new_point(px, py),
		0x702963);
}
