/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/14 15:41:35 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	wall_collision(t_data *data, double pdx, double pdy, double move_step)
{
	int		old_px;
	int		old_py;
	int		new_px;
	int		new_py;
	t_point	old_point;

	old_px = floor(data->player.pos.x / TILE_SIZE);
	old_py = floor(data->player.pos.y / TILE_SIZE);
	new_px = floor((data->player.pos.x + (pdx * move_step)) / TILE_SIZE);
	new_py = floor((data->player.pos.y + (pdy * move_step)) / TILE_SIZE);
	old_point = data->player.pos;
	if (data->pars->map[new_py][old_px] == '0'
		|| data->pars->map[new_py][old_px] == 'O')
	{
		if (data->pars->map[old_py][new_px] == '0'
			|| data->pars->map[old_py][new_px] == 'O')
		{
				data->player.pos.x += pdx * move_step;
				data->player.pos.y += pdy * move_step;
		}
	}
	if (data->pars->map[new_py][new_px] != '0'
		&& data->pars->map[new_py][new_px] != 'O')
		data->player.pos = old_point;
}

void	handle_arrows(int keycode, t_data *data, double rotation_speed)
{
	if (keycode == UP)
	{
		data->player.moves++;
		data->player.walk_direction = 1;
	}
	else if (keycode == DOWN)
	{
		data->player.moves++;
		data->player.walk_direction = -1;
	}
}

void	handle_side_walk(int key, t_data *data)
{
	if (key == A_KEY)
		data->player.side_direction = -1;
	else
		data->player.side_direction = 1;
}

// since W and S will behave like the arrows keys
// we just gonna use the same function
int	action(int keycode, t_data *data)
{
	if (keycode == ESC)
		free_exit(data, 0);
	else if (keycode >= LEFT && keycode <= UP)
		handle_arrows(keycode, data, 1);
	else if (keycode == W_KEY)
		handle_arrows(UP, data, 1);
	else if (keycode == S_KEY)
		handle_arrows(DOWN, data, 1);
	else if (keycode == A_KEY || keycode == D_KEY)
		handle_side_walk(keycode, data);
	else if (keycode == SPACE)
	{
		if (data->door.is_any_door_nearby)
		{
			if (data->pars->map[data->door.y][data->door.x] == 'O'
				&& !data->action_open)
				data->action_close = TRUE;
			else if (!data->action_close)
				data->action_open = TRUE;
		}
	}
	else if (keycode == M_KEY)
		data->show_map = !data->show_map;
	return (0);
}

int	action_key_up(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN
		|| keycode == W_KEY || keycode == S_KEY)
		data->player.walk_direction = 0;
	else if (keycode == RIGHT || keycode == LEFT)
		data->player.turn_direction = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		data->player.side_direction = 0;
	return (0);
}
