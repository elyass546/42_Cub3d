/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/25 17:39:50 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

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
	data->frames.f1 = mlx_xpm_file_to_image(data->mlx, "./frames/frame1.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f2 = mlx_xpm_file_to_image(data->mlx, "./frames/frame2.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f3 = mlx_xpm_file_to_image(data->mlx, "./frames/frame3.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f4 = mlx_xpm_file_to_image(data->mlx, "./frames/frame4.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f5 = mlx_xpm_file_to_image(data->mlx, "./frames/frame5.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f6 = mlx_xpm_file_to_image(data->mlx, "./frames/frame6.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f7 = mlx_xpm_file_to_image(data->mlx, "./frames/frame7.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f8 = mlx_xpm_file_to_image(data->mlx, "./frames/frame8.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f9 = mlx_xpm_file_to_image(data->mlx, "./frames/frame9.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f10 = mlx_xpm_file_to_image(data->mlx, "./frames/frame10.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f11 = mlx_xpm_file_to_image(data->mlx, "./frames/frame11.xpm",
		&data->frames.x, &data->frames.y);
	data->frames.f12 = mlx_xpm_file_to_image(data->mlx, "./frames/frame12.xpm",
		&data->frames.x, &data->frames.y);
	data->text.north = mlx_xpm_file_to_image(data->mlx, "./frames/coal.xpm",
		&data->frames.x, &data->frames.y);
	data->text.west = mlx_xpm_file_to_image(data->mlx, "./frames/cobblestone.xpm",
		&data->frames.x, &data->frames.y);
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
	data->player.walk_speed = 10;
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
	data->img.img = NULL;
	data->pars = pars;
	init_player_config(data);
	init_animation_frames(data);
	return (data);
}