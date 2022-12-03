/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/01 23:14:41 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	is_ray_facing_down(float ray_angle)
{
	if (ray_angle > 0 && ray_angle < PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_facing_right(float ray_angle)
{
	if (ray_angle < P2 || ray_angle > P3)
		return (TRUE);
	else
		return (FALSE);
}

void	cast_single_ray(t_data *data, t_ray *ray)
{
	float	ca;

	init_ray(ray);
	find_horizontal_wall(data, ray);
	find_vertical_wall(data, ray);
	ray->dist_v = calculate_distance(data->player.pos, ray->vertical_hit);
	ray->dist_h = calculate_distance(data->player.pos, ray->horizontal_hit);
	if (ray->dist_v < ray->dist_h)
	{
		ray->was_hit_vertical = TRUE;
		ray->dist_f = ray->dist_v;
		ray->wall_hit.x = ray->vertical_hit.x;
		ray->wall_hit.y = ray->vertical_hit.y;
	}
	else
	{
		ray->dist_f = ray->dist_h;
		ray->was_hit_vertical = FALSE;
		ray->wall_hit.x = ray->horizontal_hit.x;
		ray->wall_hit.y = ray->horizontal_hit.y;
	}
	ca = rad_addition(data->player.rotation_angle, -ray->ray_angle);
	ray->dist_f *= cos(ca);
	draw_wall(data, ray);
}

void	cast_rays(t_data *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	ray.ray_angle = rad_addition(data->player.rotation_angle, -HALF_FOV);
	ray.h = 0;
	while (i < WIDTH)
	{
		cast_single_ray(data, &ray);
		i++;
		ray.ray_angle = rad_addition(ray.ray_angle, FOV / WIDTH);
	}
}
