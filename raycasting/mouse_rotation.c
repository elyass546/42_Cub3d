/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:09:09 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/27 00:02:29 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//rotate with mouse

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