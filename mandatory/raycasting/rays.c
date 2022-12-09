/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/09 21:52:25 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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

void	cast_single_ray(t_data *data, t_ray *ray)
{
	double	ca;

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
	ray.ray_angle = rad_addition(data->player.rotation_angle, (-M_PI / 6));
	ray.h = 0;
	while (i < WIDTH)
	{
		cast_single_ray(data, &ray);
		i++;
		ray.ray_angle = rad_addition(ray.ray_angle, (M_PI / 3) / WIDTH);
	}
}
