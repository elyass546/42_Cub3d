/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/12 13:03:32 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

int	is_ray_facing_down(double ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_facing_right(double ray_angle)
{
	if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
		return (TRUE);
	else
		return (FALSE);
}

int	mouse_rotation(int x, int y, t_data *param)
{
	(void)y;
	if (param->player.mouse_rotation < x)
		param->player.turn_direction = 1;
	else if (param->player.mouse_rotation > x)
		param->player.turn_direction = -1;
	param->player.mouse_rotation = x;
	if (param->player.mouse_rotation > WIDTH
		|| param->player.mouse_rotation < 0)
		mlx_mouse_move(param->win, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
	return (0);
}
