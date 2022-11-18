/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/18 17:21:30 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

int	is_ray_facing_down(float ray_angle)
{
	if (ray_angle > 0 && ray_angle < PI)
		return (TRUE);
	else
		return (FALSE);
}

int	is_ray_faceing_right(float ray_angle)
{
	if (ray_angle < PI / 2 || ray_angle > P3)
		return (TRUE);
	else
		return (FALSE);
}

void	init_ray(t_ray *ray)
{
	ray->is_ray_facing_down = is_ray_facing_down(ray->ray_angle);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	
	ray->is_ray_facing_right = is_ray_facing_right(ray->ray_angle);
	ray->is_ray_facing_left = !ray->is_ray_facing_right;

	
}

void	cast_single_ray(t_data *data, t_ray *ray)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		found_wallH_hit = FALSE;
	float	wallH_hit_x;
	float	wallH_hit_y;
	
	init_ray(ray);
	yintercept = floor(data->player.pos.y / TILE_SIZE) * TILE_SIZE;
	yintercept += ray->is_ray_facing_down ? TILE_SIZE : 0;

	xintercept = data->player.pos.x + (yintercept - data->player.pos.y) / tan(ray->ray_angle);
	
	
}

void	cast_rays(t_data *data)
{
	t_ray	ray[60]; // to change to the screen width later
	float	ray_angle;
	int		i;

	ray_angle = rad_addition(data->player.rotation_angle, - HALF_FOV);
	i = 0;
	while (i < 60)
	{
		ray[i].ray_angle = ray_angle;
		cast_single_ray(data, &ray[i]);
		i++;
		
		ray_angle += FOV / 60;
		ray_angle = rad_addition(ray_angle, FOV / 60);
	}
	
}