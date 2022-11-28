/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/28 20:21:57 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycasting_bonus.h"

//move with mouse

int		mouse_rotation(int x, int y, t_data *param)
{
	(void)y;

	if (param->player.mouse_rotation < x)
		handle_arrows(RIGHT, param, x - param->player.mouse_rotation);
	else if (param->player.mouse_rotation > x)
		handle_arrows(LEFT, param, param->player.mouse_rotation - x);
	param->player.mouse_rotation = x;
	param->player.turn_direction = 0;
	if (param->player.mouse_rotation > WIDTH || param->player.mouse_rotation < 0)
		mlx_mouse_move(param->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}