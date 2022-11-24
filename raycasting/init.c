/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/24 15:33:13 by mkorchi          ###   ########.fr       */
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

static void	init_player_config(t_data *data)
{
	// define pos of player
	data->player.pos.x = data->pars->player_x * TILE_SIZE;
	data->player.pos.y = data->pars->player_y * TILE_SIZE;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.mouse_rotation = 0;
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
	return (data);
}