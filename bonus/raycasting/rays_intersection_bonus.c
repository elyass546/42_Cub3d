/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_intersection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:40:44 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 13:00:46 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	init_ray(t_ray *ray)
{
	ray->is_ray_facing_down = is_ray_facing_down(ray->ray_angle);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = is_ray_facing_right(ray->ray_angle);
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	ray->distH = 100000;
	ray->distV = 100000;
	ray->wall_hit_content = '0';
	ray->horizontal_content = '0';
	ray->vertical_content = '0';
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
		ray->rx = floor(data->player.pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray->ry = data->player.pos.y + (ray->rx - data->player.pos.x)
			* tan(ray->ray_angle);
		ray->x0 = TILE_SIZE;
		ray->y0 = ray->x0 * tan(ray->ray_angle);
	}
}

void	find_vertical_wall(t_data *data, t_ray *ray)
{
	find_first_vertical_intersection(data, ray);
	while (TRUE)
	{
		ray->mx = (int)(ray->rx) / TILE_SIZE;
		ray->my = (int)(ray->ry) / TILE_SIZE;
		if (ray->mx < 0 || ray-> my < 0 || ray->my >= data->pars->row
			|| ray->mx >= (int) ft_strlen(data->pars->map[ray->my]))
		{
			ray->vertical_hit.x = ray->rx;
			ray->vertical_hit.y = ray->ry;
			break ;
		}
		if (data->pars->map[ray->my][ray->mx] == '1'
			|| data->pars->map[ray->my][ray->mx] == 'D')
		{
			ray->vertical_hit.x = ray->rx;
			ray->vertical_hit.y = ray->ry;
			ray->vertical_content = data->pars->map[ray->my][ray->mx];
			break ;
		}
		else
			check_if_any_open_doors(data, ray);
	}
}

void	find_first_horizontal_intersection(t_data *data, t_ray *ray)
{
	if (ray->is_ray_facing_up)
	{
		ray->ry = floor(data->player.pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
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
	find_first_horizontal_intersection(data, ray);
	while (TRUE)
	{
		ray->mx = (int)(ray->rx) / TILE_SIZE;
		ray->my = (int)(ray->ry) / TILE_SIZE;
		if (ray->mx < 0 || ray->my < 0 || ray->my >= data->pars->row || ray->mx
			>= (int) ft_strlen(data->pars->map[ray->my]))
		{
			ray->horizontal_hit.x = ray->rx;
			ray->horizontal_hit.y = ray->ry;
			break ;
		}
		if (data->pars->map[ray->my][ray->mx] == '1'
			|| data->pars->map[ray->my][ray->mx] == 'D')
		{
			ray->horizontal_hit.x = ray->rx;
			ray->horizontal_hit.y = ray->ry;
			ray->horizontal_content = data->pars->map[ray->my][ray->mx];
			break ;
		}
		else
			check_if_any_open_doors(data, ray);
	}
}
