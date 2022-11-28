/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/28 17:15:01 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

//move with mouse

int		mouse_rotation(int	x, int y, t_data *param)
{
	(void)y;
	int	rotation_speed;

	rotation_speed = abs(param->player.mouse_rotation - x);
	if (param->player.mouse_rotation < x)
		handle_arrows(RIGHT, param, rotation_speed);
	else if (param->player.mouse_rotation > x)
		handle_arrows(LEFT, param, rotation_speed);
	param->player.mouse_rotation = x;
	param->player.turn_direction = 0;
	return (0);
}