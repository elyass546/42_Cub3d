/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/28 19:42:32 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "raycasting_bonus.h"

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
	// free_map(data->map);
	free(data);
	exit(status);
}

static float	get_player_angle(char c)
{
	if (c == 'N')
		return (P3);
	if (c == 'S')
		return (PI / 2);
	if (c == 'E')
		return (0);
	return (PI);
}

static void	init_animation_frames(t_data *data)
{
	// init frame from xpm file to image
	data->frames.f1 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame1.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f2 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame2.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f3 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame3.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f4 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame4.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f5 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame5.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f6 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame6.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f7 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame7.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f8 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame8.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f9 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame9.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f10 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame10.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f11 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame11.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f12 = mlx_xpm_file_to_image(data->mlx, "./sprites/frame12.xpm",
		&data->frames.x, &data->frames.y);
	data->text.north.img = mlx_xpm_file_to_image(data->mlx, data->pars->north,
		&data->frames.x, &data->frames.y);
	data->text.north.addr = mlx_get_data_addr(data->text.north.img, &data->text.north.bits_per_pixel,
		&data->text.north.line_length, &data->text.north.endian);
		
	data->text.east.img = mlx_xpm_file_to_image(data->mlx, data->pars->east,
		&data->frames.x, &data->frames.y);
	data->text.east.addr = mlx_get_data_addr(data->text.east.img, &data->text.east.bits_per_pixel,
		&data->text.east.line_length, &data->text.east.endian);
	
	data->text.west.img = mlx_xpm_file_to_image(data->mlx, data->pars->west,
		&data->frames.x, &data->frames.y);
	data->text.west.addr = mlx_get_data_addr(data->text.west.img, &data->text.west.bits_per_pixel,
		&data->text.west.line_length, &data->text.west.endian);

	data->text.south.img = mlx_xpm_file_to_image(data->mlx, data->pars->south,
		&data->frames.x, &data->frames.y);
	data->text.south.addr = mlx_get_data_addr(data->text.south.img, &data->text.south.bits_per_pixel,
		&data->text.south.line_length, &data->text.south.endian);
	
	data->text.door.img = mlx_xpm_file_to_image(data->mlx, "./frames/eagle.xpm",
		&data->frames.x, &data->frames.y);
	data->text.door.addr = mlx_get_data_addr(data->text.door.img, &data->text.door.bits_per_pixel,
		&data->text.door.line_length, &data->text.door.endian);
}

static void	init_player_config(t_data *data)
{
	// define pos of player
	data->player.pos.x = data->pars->player_x * TILE_SIZE;
	data->player.pos.y = data->pars->player_y * TILE_SIZE;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.mouse_rotation = 0;
	data->frames.x = 0;
	data->frames.y = 0;
	data->player.moves = 0;
	data->player.rotation_angle = get_player_angle(data->pars->player_pos);
	data->player.walk_speed = 25;
	data->player.turn_speed = deg2rad(5);
	data->player.height = 5;
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
	init_animation_frames(data);
	return (data);
}