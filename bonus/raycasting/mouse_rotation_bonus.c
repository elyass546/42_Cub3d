/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/26 23:04:09 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

//move with mouse

int		mouse_rotation(int	x, int y, t_data *param)
{
	(void)y;
	if (param->player.mouse_rotation < x)
		handle_arrows(RIGHT, param);
	else if (param->player.mouse_rotation > x)
		handle_arrows(LEFT, param);
	param->player.mouse_rotation = x;
	return (0);
}