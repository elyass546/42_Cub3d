/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/11 20:32:37 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

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

void	init_drawing(t_data *data, t_ray *ray, int wall_strip_height)
{
	ray->top_pixel = HEIGHT / 2 - wall_strip_height / 2;
	ray->bot_pixel = HEIGHT / 2 + wall_strip_height / 2;
	if (ray->top_pixel < 0)
		ray->top_pixel = 0;
	if (ray->bot_pixel > HEIGHT)
		ray->bot_pixel = HEIGHT;
	if (ray->was_hit_vertical)
	{
		ray->texture_offsetx = (int) ray->wall_hit.y % TILE_SIZE;
		if (ray->is_ray_facing_left)
			ray->img = &data->text.east;
		if (ray->is_ray_facing_right)
			ray->img = &data->text.west;
	}
	else
	{
		ray->texture_offsetx = (int) ray->wall_hit.x % TILE_SIZE;
		if (ray->is_ray_facing_up)
			ray->img = &data->text.north;
		if (ray->is_ray_facing_down)
			ray->img = &data->text.south;
	}
}

void	check_for_doors(t_data *data, t_ray *ray)
{
	if (ray->wall_hit_content == 'D')
	{
		if (ray->distF <= 130)
		{

			data->door.x = (int) (ray->wall_hit.x) / TILE_SIZE;
			data->door.y = (int) (ray->wall_hit.y) / TILE_SIZE;
			data->door.distance  = ray->distF;
			data->door.is_any_door_nearby = TRUE;
			ray->img = data->current_door_frame;
		}
		else
			ray->img = &data->text.door;
	}
}

void	draw_wall(t_data *data, t_ray *ray)
{
	double	wall_height;
	int		wall_strip_height;

	int		y;

	wall_height = (TILE_SIZE / ray->distF) * ((WIDTH / 2 ) / tan(HALF_FOV));
	wall_strip_height = (int) wall_height;
	init_drawing(data, ray, wall_strip_height);
	dda(&data->img, new_point(ray->h, 0), new_point(ray->h, ray->top_pixel), data->pars->ceilling);
	check_for_doors(data, ray);
	y = ray->top_pixel;
	while (y < ray->bot_pixel)
	{
		ray->texture_offsety = (y + (wall_strip_height / 2 )
			- (HEIGHT / 2)) * (64.0f / wall_strip_height);
		unsigned int color = my_mlx_get_color(ray->img, ray->texture_offsetx, ray->texture_offsety);
		my_mlx_pixel_put(&data->img, ray->h, y, color);
		y++;
	}
	dda(&data->img, new_point(ray->h, ray->bot_pixel), new_point(ray->h, HEIGHT), data->pars->floor);
	ray->h++;
}

void	cast_single_ray(t_data *data, t_ray *ray)
{
	init_ray(ray);
	find_horizontal_wall(data, ray);
	find_vertical_wall(data, ray);
	ray->distV = calculate_distance(data->player.pos, ray->vertical_hit);
	ray->distH = calculate_distance(data->player.pos, ray->horizontal_hit);

	if (ray->distV < ray->distH)
	{
		ray->was_hit_vertical = TRUE;
		ray->distF = ray->distV;
		ray->wall_hit.x = ray->vertical_hit.x;
		ray->wall_hit.y = ray->vertical_hit.y;
		ray->wall_hit_content = ray->vertical_content;
	}
	else
	{
		ray->distF = ray->distH;
		ray->was_hit_vertical = FALSE;
		ray->wall_hit_content = ray->horizontal_content;
		ray->wall_hit.x = ray->horizontal_hit.x;
		ray->wall_hit.y = ray->horizontal_hit.y;
	}
	double ca = rad_addition(data->player.rotation_angle, -ray->ray_angle);
	ray->distF *= cos(ca);
	draw_wall(data, ray);
}

void	cast_rays(t_data *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	ray.ray_angle = rad_addition(data->player.rotation_angle, -HALF_FOV);
	ray.h = 0;
	data->door.is_any_door_nearby = FALSE;
	data->door.distance = 1000000;
	while (i < WIDTH)
	{
		cast_single_ray(data, &ray);
		i++;
		ray.ray_angle = rad_addition(ray.ray_angle, FOV / WIDTH);
	}
}
