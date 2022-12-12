/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 16:20:17 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	free_exit(t_data *data, int status)
{
	if (status)
		ft_putstr_fd("ERROR\n", 2);
	if (data->mlx)
	{
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	free(data);
	exit(status);
}

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

static void	init_textures(t_data *data)
{
	data->text.north.img = mlx_xpm_file_to_image(data->mlx, data->pars->north,
			&data->frames.x, &data->frames.y);
	data->text.north.addr = mlx_get_data_addr(data->text.north.img,
			&data->text.north.bits_per_pixel, &data->text.north.line_length,
			&data->text.north.endian);
	data->text.east.img = mlx_xpm_file_to_image(data->mlx, data->pars->east,
			&data->frames.x, &data->frames.y);
	data->text.east.addr = mlx_get_data_addr(data->text.east.img,
			&data->text.east.bits_per_pixel, &data->text.east.line_length,
			&data->text.east.endian);
	data->text.west.img = mlx_xpm_file_to_image(data->mlx, data->pars->west,
			&data->frames.x, &data->frames.y);
	data->text.west.addr = mlx_get_data_addr(data->text.west.img,
			&data->text.west.bits_per_pixel, &data->text.west.line_length,
			&data->text.west.endian);
	data->text.south.img = mlx_xpm_file_to_image(data->mlx, data->pars->south,
			&data->frames.x, &data->frames.y);
	data->text.south.addr = mlx_get_data_addr(data->text.south.img,
			&data->text.south.bits_per_pixel, &data->text.south.line_length,
			&data->text.south.endian);
}

static void	init_player_config(t_data *data)
{
	data->player.pos.x = data->pars->player_x * TILE_SIZE + TILE_SIZE / 2;
	data->player.pos.y = data->pars->player_y * TILE_SIZE + TILE_SIZE / 2;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 0;
	data->player.mouse_rotation = 0;
	data->frames.x = 0;
	data->frames.y = 0;
	data->player.moves = 0;
	data->player.rotation_angle = get_player_angle(data->pars->player_pos);
	data->player.walk_speed = 6;
	data->player.turn_speed = deg2rad(1.5);
}

t_data	*init_data( t_pars *pars )
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->height = pars->row * SCALE;
	data->width = pars->col * SCALE;
	data->show_map = TRUE;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->i = 0;
	data->j = 0;
	data->img.img = NULL;
	data->pars = pars;
	init_player_config(data);
	init_textures(data);
	init_door_animation(data);
	init_gun_animation(data);
	data->current_door_frame = &data->text.door;
	data->action_close = FALSE;
	data->action_open = FALSE;
	data->action_shoot = FALSE;
	return (data);
}
