/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/14 17:34:34 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static double	get_player_angle(char c)
{
	if (c == 'N')
		return (3 * M_PI_2);
	if (c == 'S')
		return (M_PI_2);
	if (c == 'E')
		return (0);
	return (M_PI);
}

void	*get_img(t_data *data, char *path)
{
	void	*img;
	int		i;

	img = mlx_xpm_file_to_image(data->mlx,
			path, &i, &i);
	if (!img)
	{
		ft_error("Texture Error\n");
		free(data);
		exit(1);
	}
	return (img);
}

static void	init_textures(t_data *data)
{
	data->text.north.img = get_img(data, data->pars->north);
	data->text.north.addr = mlx_get_data_addr(data->text.north.img,
			&data->text.north.bits_per_pixel, &data->text.north.line_length,
			&data->text.north.endian);
	data->text.east.img = get_img(data, data->pars->east);
	data->text.east.addr = mlx_get_data_addr(data->text.east.img,
			&data->text.east.bits_per_pixel,
			&data->text.east.line_length, &data->text.east.endian);
	data->text.west.img = get_img(data, data->pars->west);
	data->text.west.addr = mlx_get_data_addr(data->text.west.img,
			&data->text.west.bits_per_pixel,
			&data->text.west.line_length, &data->text.west.endian);
	data->text.south.img = get_img(data, data->pars->south);
	data->text.south.addr = mlx_get_data_addr(data->text.south.img,
			&data->text.south.bits_per_pixel,
			&data->text.south.line_length, &data->text.south.endian);
}

// define pos of player
static void	init_player_config(t_data *data)
{
	data->player.pos.x = data->pars->player_x * TILE_SIZE + TILE_SIZE / 2;
	data->player.pos.y = data->pars->player_y * TILE_SIZE + TILE_SIZE / 2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 0;
	data->player.rotation_angle = get_player_angle(data->pars->player_pos);
	data->player.walk_speed = 5;
	data->player.turn_speed = deg2rad(1);
}

// later WIDTH AND HEIGHT WILL BE FIX
t_data	*init_data( t_pars *pars )
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->height = pars->row * TILE_SIZE;
	data->width = pars->col * TILE_SIZE;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->i = 0;
	data->img.img = NULL;
	data->pars = pars;
	init_player_config(data);
	init_textures(data);
	return (data);
}
