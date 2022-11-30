/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/30 18:53:56 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raycasting_bonus.h"

//move with mouse

int		mouse_rotation(int x, int y, t_data *param)
{
	(void)y;

	if (param->player.mouse_rotation < x)
		param->player.turn_direction = 1;
	else if (param->player.mouse_rotation > x)
		param->player.turn_direction = -1;
	param->player.mouse_rotation = x;
	if (param->player.mouse_rotation > WIDTH || param->player.mouse_rotation < 0)
		mlx_mouse_move(param->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
	// param->player.turn_direction = 0;
	return (0);
}