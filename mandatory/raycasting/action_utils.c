/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:15:42 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/01 13:16:10 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	handle_arrows(int keycode, t_data *data)
{
	if (keycode == RIGHT)
		data->player.turn_direction = 1;
	else if (keycode == LEFT)
		data->player.turn_direction = -1;
	else if (keycode == UP)
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
		handle_arrows(keycode, data);
	else if (keycode == W_KEY)
		handle_arrows(UP, data);
	else if (keycode == S_KEY)
		handle_arrows(DOWN, data);
	else if (keycode == A_KEY || keycode == D_KEY)
		handle_side_walk(keycode, data);
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