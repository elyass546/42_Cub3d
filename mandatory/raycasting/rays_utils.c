/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:10:40 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/03 15:35:05 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_wall_utils(t_data *data, t_ray *ray, t_wall *wall)
{
	wall->wall_h = (TILE_SIZE / ray->dist_f) * ((WIDTH / 2) / tan(HALF_FOV));
	wall->wall_strip_height = (int) wall->wall_h;
	wall->top_pixel = HEIGHT / 2 - wall->wall_strip_height / 2;
	wall->bot_pixel = HEIGHT / 2 + wall->wall_strip_height / 2;
	if (wall->top_pixel < 0)
		wall->top_pixel = 0;
	if (wall->bot_pixel > HEIGHT)
		wall->bot_pixel = HEIGHT;
	if (ray->was_hit_vertical)
	{
		wall->texture_offsetx = (int) ray->wall_hit.y % TILE_SIZE;
		if (ray->is_ray_facing_left)
			wall->img = &data->text.east;
		if (ray->is_ray_facing_right)
			wall->img = &data->text.west;
	}
	else
	{
		wall->texture_offsetx = (int) ray->wall_hit.x % TILE_SIZE;
		if (ray->is_ray_facing_up)
			wall->img = &data->text.north;
		if (ray->is_ray_facing_down)
			wall->img = &data->text.south;
	}
}

void	draw_wall(t_data *data, t_ray *ray)
{
	t_wall	wall;
	int		y;

	draw_wall_utils(data, ray, &wall);
	y = 0;
	while (y < wall.top_pixel)
		my_mlx_pixel_put(&data->img, ray->h, y++, data->pars->ceilling);
	while (y < wall.bot_pixel)
	{
		wall.distance_from_top = y
			+ (wall.wall_strip_height / 2) - (HEIGHT / 2);
		wall.texture_offsety = wall.distance_from_top
			* (64.0f / wall.wall_strip_height);
		wall.color = my_mlx_get_color(wall.img, wall.texture_offsetx,
				wall.texture_offsety);
		my_mlx_pixel_put(&data->img, ray->h, y, wall.color);
		y++;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(&data->img, ray->h, y++, data->pars->floor);
	ray->h++;
}
