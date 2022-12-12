/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:00:30 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 13:02:30 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	check_for_doors(t_data *data, t_ray *ray)
{
	if (ray->wall_hit_content == 'D')
	{
		if (ray->distF <= 130)
		{
			data->door.x = (int)(ray->wall_hit.x) / TILE_SIZE;
			data->door.y = (int)(ray->wall_hit.y) / TILE_SIZE;
			data->door.distance = ray->distF;
			data->door.is_any_door_nearby = TRUE;
			ray->img = data->current_door_frame;
		}
		else
			ray->img = &data->text.door;
	}
}

void	check_if_any_open_doors(t_data *data, t_ray *ray)
{
	if (data->pars->map[ray->my][ray->mx] == 'O')
	{
		if (calculate_distance(data->player.pos,
				new_point(ray->rx, ray->ry)) <= 130)
		{
			data->door.is_any_door_nearby = TRUE;
			data->door.is_open = FALSE;
			data->door.x = ray->mx;
			data->door.y = ray->my;
		}
	}
	ray->rx += ray->x0;
	ray->ry += ray->y0;
}
