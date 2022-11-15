/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:51:48 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/15 15:39:51 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

void	draw_square(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 1;
	while (i < TILE_SIZE - 1)
	{
		j = 1;
		while (j < TILE_SIZE - 1)
		{
			my_mlx_pixel_put(img, x + j, y + i, color);
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
			draw_square(&data->img, j * TILE_SIZE, i * TILE_SIZE, color);
			// printf("%c ", data->pars->map[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
}