/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:50 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/05 12:51:50 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting_bonus.h"

void	draw_minimap(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;
	int	offset_x;
	int	offset_y;
	
	i = 0;
	offset_y = y - 4;
	// printf("x: %d\n", offset_x);
	// printf("y: %d\n", offset_y);
	while (i < 9)
	{
		j = 0;
		offset_x = x - 4;
		while (j < 9)
		{
			if (offset_x < 0 || offset_y < 0
				|| offset_y >= data->pars->row
				|| offset_x >= ft_strlen(data->pars->map[offset_y]))
			{
				color = 0x000000;
			}
			else if (data->pars->map[offset_y][offset_x] == '1')
				color = 0x00FFFFFF;
			else if (data->pars->map[offset_y][offset_x] == ' ')
				color = 0x00000000;
			else if (data->pars->map[offset_y][offset_x] == 'D')
				color = 0x00FFD700;
			else if (data->pars->map[offset_y][offset_x] == 'O')
				color = 0x00808080;
			else
				color = 0x00808080;
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

void	draw_player_in_map(t_data *data, int x, int y)
{
	// double grid_x = data->player.pos.x / TILE_SIZE;
	// double grid_y = data->player.pos.y / TILE_SIZE;

	draw_square(&data->img,
		new_point(SCALE * 4 , SCALE * 4 ),
			0x702963,
				10);
	float px = (4 * SCALE) + cos(data->player.rotation_angle) * 25;
	float py = (4 * SCALE) + sin(data->player.rotation_angle) * 25;
	dda(&data->img,
		new_point(4 * SCALE + 5, SCALE * 4 + 5),
			new_point(px + 5, py + 5),
				0x702963);
}

void	mini_map(t_data *data)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int) (data->player.pos.x / TILE_SIZE);
	grid_y = (int) (data->player.pos.y / TILE_SIZE);
	draw_minimap(data, grid_x, grid_y);
	draw_player_in_map(data, grid_x, grid_y);
}