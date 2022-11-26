/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:10:31 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/26 13:21:50 by mkorchi          ###   ########.fr       */
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
		y0 = -TILE_SIZE;
		x0 = y0 / tan(ray->ray_angle);
	}
	else
	{
		ry = floor(data->player.pos.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		rx = data->player.pos.x + (ry - data->player.pos.y) / tan(ray->ray_angle);
		y0 = TILE_SIZE;
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
		if (data->pars->map[my][mx] == '1' || data->pars->map[my][mx] == 'P')
		{
			ray->horizontal_hit.x = rx;
			ray->horizontal_hit.y = ry;
			ray->wall_hit_content = data->pars->map[my][mx];
			break ;
		}
		else
		{
			rx += x0;
			ry += y0;
		}
	}
}

void	draw_wall(t_data *data, t_ray *ray)
{
	float	wallH;
	int		wall_strip_height;
	int		top_pixel;
	int		bot_pixel;

	wallH =  (TILE_SIZE / ray->distF) * ((WIDTH / 2 ) / tan(HALF_FOV));
	wall_strip_height = (int) wallH;
	// wallH = (int) ((HEIGHT / 2 ) / tan(HALF_FOV)) * 64  / ray->distF;
	top_pixel = HEIGHT / 2 - wall_strip_height / 2;
	bot_pixel = HEIGHT / 2 + wall_strip_height / 2;
	if (top_pixel < 0)
		top_pixel = 0;
	if (bot_pixel > HEIGHT)
		bot_pixel = HEIGHT;
	int	texture_offsetx;
	t_img	*img;
	if (ray->was_hit_vertical)
	{
		texture_offsetx = (int) ray->vertical_hit.y % TILE_SIZE;
		if (ray->is_ray_facing_left)
			img = &data->text.east;
		if (ray->is_ray_facing_right)
			img = &data->text.west;
	}
	else
	{
		texture_offsetx = (int) ray->horizontal_hit.x % TILE_SIZE;
		if (ray->is_ray_facing_up)
			img = &data->text.north;
		if (ray->is_ray_facing_down)
			img = &data->text.south;
	}
	int	y = 0;
	while (y < top_pixel)
	{
		my_mlx_pixel_put(&data->img, ray->h, y, data->pars->ceilling);
		y++;
	}
	if (ray->wall_hit_content == 'P')
		img = &data->text.door;
	while (y < bot_pixel)
	{
		int	distance_from_top = y + (wall_strip_height / 2 ) - (HEIGHT / 2);
		int texture_offsety = distance_from_top * (64.0f / wall_strip_height);
		unsigned int color = my_mlx_get_color(img, texture_offsetx, texture_offsety);
		my_mlx_pixel_put(&data->img, ray->h, y, color);
		y++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, ray->h, y, data->pars->floor);
		y++;
	}
	ray->h++;
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
		// dda(&data->img, data->player.pos, ray->vertical_hit, 0x00FF0000);
	}
	else
	{
		ray->distF = ray->distH;
		ray->was_hit_vertical = FALSE;
		// dda(&data->img, data->player.pos, ray->horizontal_hit, 0x00FF0000);
	}
	float ca = rad_addition(data->player.rotation_angle, -ray->ray_angle);
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
	while (i < WIDTH)
	{
		cast_single_ray(data, &ray);
		i++;
		ray.ray_angle = rad_addition(ray.ray_angle, FOV / WIDTH);
	}
}