/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/16 15:55:27 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

void	move_player(t_player *player)
{
	t_point	new_player_pos;
	float	move_step;
	
	player->rotation_angle += player->turn_direction * player->turn_speed;
	move_step = player->walk_direction * player->walk_speed;
	
	new_player_pos.x = player->pos.x + cos(player->rotation_angle) * move_step;
	new_player_pos.y = player->pos.y + sin(player->rotation_angle) * move_step;
	player->pos = new_player_pos;
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	draw_walls(data);
	move_player(&data->player);
	draw_player(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	handle_arrow(int keycode, t_data *data)
{
	if (keycode == RIGHT)
		data->player.turn_direction = 1;
	else if (keycode == LEFT)
		data->player.turn_direction = -1;
	else if (keycode == UP)
		data->player.walk_direction = 1;
	else if (keycode == DOWN)
		data->player.walk_direction = -1;
	update_screen(data);
}

int	action(int keycode, t_data *data)
{
	if (keycode == ESC)
		free_exit(data, 0);
	else if (keycode >= LEFT && keycode <= UP)
	{
		handle_arrow(keycode, data);	
	}
	return (0);
}

int	action_key_up(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN)
		data->player.walk_direction = 0;
	else if (keycode == RIGHT || keycode == LEFT)
		data->player.turn_direction = 0;
		
	return (0);
}