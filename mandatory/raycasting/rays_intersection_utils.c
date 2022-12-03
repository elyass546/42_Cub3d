/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_intersection_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:49:15 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/03 15:51:57 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	find_vertical_wall_helper(int mx, int my, t_data *data, t_ray *ray)
{
	mx = (int)(ray->rx) / TILE_SIZE;
	my = (int)(ray->ry) / TILE_SIZE;
	if (mx < 0 || my < 0 || my >= data->pars->row
		|| mx >= (int) ft_strlen(data->pars->map[my]))
	{
		ray->vertical_hit.x = ray->rx;
		ray->vertical_hit.y = ray->ry;
		return (1);
	}
	if (data->pars->map[my][mx] == '1')
	{
		ray->vertical_hit.x = ray->rx;
		ray->vertical_hit.y = ray->ry;
		return (1);
	}
	return (0);
}

int	find_horizontal_wall_helper(int mx, int my, t_data *data, t_ray *ray)
{
	mx = (int)(ray->rx) / TILE_SIZE;
	my = (int)(ray->ry) / TILE_SIZE;
	if (mx < 0 || my < 0 || my >= data->pars->row
		|| mx >= (int) ft_strlen(data->pars->map[my]))
	{
		ray->horizontal_hit.x = ray->rx;
		ray->horizontal_hit.y = ray->ry;
		return (1);
	}
	if (data->pars->map[my][mx] == '1')
	{
		ray->horizontal_hit.x = ray->rx;
		ray->horizontal_hit.y = ray->ry;
		return (1);
	}
	return (0);
}
