/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/16 17:44:18 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

int	wall_collision(t_data *data, float x, float y)
{
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return TRUE;
	int grid_x = floor(x / TILE_SIZE);
	int grid_y = floor(y / TILE_SIZE);
	if (data->pars->map[grid_y][grid_x] != '0')
		return TRUE;
	return FALSE; 
}

void	move_player(t_data *data)
{
	t_point		new_player_pos;
	float		move_step;
	t_player	*player;
	
	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	move_step = player->walk_direction * player->walk_speed;
	
	new_player_pos.x = player->pos.x + cos(player->rotation_angle) * move_step;
	new_player_pos.y = player->pos.y + sin(player->rotation_angle) * move_step;
	if (!wall_collision(data, new_player_pos.x, new_player_pos.y))
		player->pos = new_player_pos;
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	draw_walls(data);
	move_player(data);
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