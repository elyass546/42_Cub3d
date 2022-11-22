/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/22 18:48:07 by mkorchi          ###   ########.fr       */
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

int	is_ray_facing_right(float ray_angle)
{
	if (ray_angle < P2 || ray_angle > P3)
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

	ray->distH = 100000;
	ray->distV = 100000;
}

void	find_vertical_wall(t_data *data, t_ray *ray)
{
	float	rx;
	float	ry;
	float	x0;
	float	y0;
	
	if (ray->is_ray_facing_left)
	{
		rx = floor(data->player.pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		ry = data->player.pos.y + (rx - data->player.pos.x) * tan(ray->ray_angle);
		x0 = -TILE_SIZE;
		y0 = x0 * tan(ray->ray_angle);
	}
	else
	{
		rx = floor(data->player.pos.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ry = data->player.pos.y + (rx - data->player.pos.x) * tan(ray->ray_angle);
		x0 = TILE_SIZE;
		y0 = x0 * tan(ray->ray_angle);
	}
	while (TRUE)
	{
		int mx = (int) (rx) / TILE_SIZE;
		int	my = (int) (ry) / TILE_SIZE;
		if (mx < 0 || my < 0 || my >= data->pars->row || mx >= (int) ft_strlen(data->pars->map[my]))
		{
			ray->vertical_hit.x = rx;
			ray->vertical_hit.y = ry;
			break ;
		}
		if (data->pars->map[my][mx] == '1')
		{
			ray->vertical_hit.x = rx;
			ray->vertical_hit.y = ry;
			break ;
		}
		else
		{
			rx += x0;
			ry += y0;
		}
	}
}

void	find_horizontal_wall(t_data *data, t_ray *ray)
{
	float	rx;
	float	ry;
	float	x0;
	float	y0;

	if (ray->is_ray_facing_up)
	{
		ry = floor(data->player.pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		rx = data->player.pos.x + (ry - data->player.pos.y) / tan(ray->ray_angle);
		y0 = -64;
		x0 = y0 / tan(ray->ray_angle);
	}
	else
	{
		ry = floor(data->player.pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		rx = data->player.pos.x + (ry - data->player.pos.y) / tan(ray->ray_angle);
		y0 = 64;
		x0 = y0 / tan(ray->ray_angle);
	}
	while (TRUE)
	{
		int mx = (int) (rx) / TILE_SIZE;
		int	my = (int) (ry) / TILE_SIZE;
		if (mx < 0 || my < 0 || my >= data->pars->row || mx >= (int) ft_strlen(data->pars->map[my]))
		{
			ray->horizontal_hit.x = rx;
			ray->horizontal_hit.y = ry;
			break ;
		}
		if (data->pars->map[my][mx] == '1')
		{
			ray->horizontal_hit.x = rx;
			ray->horizontal_hit.y = ry;
			break ;
		}
		else
		{
			rx += x0;
			ry += y0;
		}
	}
}

void	cast_single_ray(t_data *data, t_ray *ray)
{
	// float	xintercept;
	// float	yintercept;
	// float	xstep;
	// float	ystep;

	int		found_wallH_hit = FALSE;
	// float	wallH_hit_x;
	// float	wallH_hit_y;
	
	init_ray(ray);
	find_horizontal_wall(data, ray);
	find_vertical_wall(data, ray);

	// dda(&data->img, data->player.pos, ray->horizontal_hit, 0x00FF0000);

	ray->distV = calculate_distance(data->player.pos, ray->vertical_hit);
	ray->distH = calculate_distance(data->player.pos, ray->horizontal_hit);

	if (ray->distV < ray->distH)
	{
		ray->was_hit_vertical = TRUE;
		ray->distF = ray->distV;
		// if (ray->vertical_hit.x > data->width)
		// 	ray->vertical_hit.x = data->width;
		// if (ray->vertical_hit.y > data->height)
		// 	ray->vertical_hit.y = data->height;
		dda(&data->img, data->player.pos, ray->vertical_hit, 0x00FF0000);
	}
	else
	{
		ray->distF = ray->distH;
		ray->was_hit_vertical = FALSE;
		dda(&data->img, data->player.pos, ray->horizontal_hit, 0x00FF0000);
	}
	
}

void	cast_rays(t_data *data)
{
	t_ray	ray[60]; // to change to the screen width later
	float	ray_angle;
	int		i;

	i = 0;
	ray_angle = rad_addition(data->player.rotation_angle, -HALF_FOV);
	// printf("%f\n", rad2deg(data->player.rotation_angle));
	// printf("%f\n", rad2deg(ray_angle));
	while (i < 60)
	{
		ray[i].ray_angle = ray_angle;
		// printf("%f\n", rad2deg(ray_angle));
	
		cast_single_ray(data, &ray[i]);
		i++;
		// ray_angle += FOV / 60;
		ray_angle = rad_addition(ray_angle, FOV / 60);
	}
}