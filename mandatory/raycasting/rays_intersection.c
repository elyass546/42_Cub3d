/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:40:44 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/14 15:08:31 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_ray(t_ray *ray)
{
	ray->is_ray_facing_down = is_ray_facing_down(ray->ray_angle);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = is_ray_facing_right(ray->ray_angle);
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	ray->dist_h = 100000;
	ray->dist_v = 100000;
}

void	find_first_vertical_intersection(t_data *data, t_ray *ray)
{
	if (ray->is_ray_facing_left)
	{
		ray->rx = floor(data->player.pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		ray->ry = data->player.pos.y + (ray->rx - data->player.pos.x)
			* tan(ray->ray_angle);
		ray->x0 = -TILE_SIZE;
		ray->y0 = ray->x0 * tan(ray->ray_angle);
	}
	else
	{
		ray->rx = floor(data->player.pos.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		ray->ry = data->player.pos.y + (ray->rx - data->player.pos.x)
			* tan(ray->ray_angle);
		ray->x0 = TILE_SIZE;
		ray->y0 = ray->x0 * tan(ray->ray_angle);
	}
}

void	find_vertical_wall(t_data *data, t_ray *ray)
{
	int	mx;
	int	my;

	find_first_vertical_intersection(data, ray);
	while (TRUE)
	{
		mx = (int)(ray->rx) / TILE_SIZE;
		my = (int)(ray->ry) / TILE_SIZE;
		if (find_vertical_wall_helper(mx, my, data, ray))
			break ;
		else
		{
			ray->rx += ray->x0;
			ray->ry += ray->y0;
		}
	}
}

void	find_first_horizontal_intersection(t_data *data, t_ray *ray)
{
	if (ray->is_ray_facing_up)
	{
		ray->ry = floor(data->player.pos.y / TILE_SIZE)
			* TILE_SIZE - 0.0001;
		ray->rx = data->player.pos.x + (ray->ry - data->player.pos.y)
			/ tan(ray->ray_angle);
		ray->y0 = -TILE_SIZE;
		ray->x0 = ray->y0 / tan(ray->ray_angle);
	}
	else
	{
		ray->ry = floor(data->player.pos.y / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
		ray->rx = data->player.pos.x + (ray->ry - data->player.pos.y)
			/ tan(ray->ray_angle);
		ray->y0 = TILE_SIZE;
		ray->x0 = ray->y0 / tan(ray->ray_angle);
	}
}

void	find_horizontal_wall(t_data *data, t_ray *ray)
{
	int	mx;
	int	my;

	mx = 0;
	my = 0;
	find_first_horizontal_intersection(data, ray);
	while (TRUE)
	{
		if (find_horizontal_wall_helper(mx, my, data, ray))
			break ;
		else
		{
			ray->rx += ray->x0;
			ray->ry += ray->y0;
		}
	}
}
