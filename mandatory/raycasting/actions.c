/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/01 14:50:01 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	if_ray_facing_down(t_data *data, int grid_x, int grid_y)
{
	float	angle;

	angle = data->player.rotation_angle;
	if (is_ray_facing_right(angle))
	{
		if (data->pars->map[grid_y - 1][grid_x] != '0'
			&& data->pars->map[grid_y][grid_x - 1] != '0')
			return (TRUE);
	}
	else
	{
		if (data->pars->map[grid_y - 1][grid_x] != '0'
			&& data->pars->map[grid_y][grid_x + 1] != '0')
			return (TRUE);
	}
}

int	if_ray_facing_up(t_data *data, int grid_x, int grid_y)
{
	float	angle;

	angle = data->player.rotation_angle;
	if (is_ray_facing_right(angle))
	{
		if (data->pars->map[grid_y][grid_x - 1] != '0'
			&& data->pars->map[grid_y + 1][grid_x] != '0')
			return (TRUE);
	}
	else
	{
		if (data->pars->map[grid_y][grid_x + 1] != '0'
			&& data->pars->map[grid_y + 1][grid_x] != '0')
			return (TRUE);
	}
}

int	wall_collision(t_data *data, float x, float y)
{
	float	angle;
	int		grid_x;
	int		grid_y;

	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (TRUE);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (data->pars->map[grid_y][grid_x] != '0')
		return (TRUE);
	angle = data->player.rotation_angle;
	if (is_ray_facing_down(angle))
		if_ray_facing_down(data, grid_x, grid_y);
	else
		if_ray_facing_up(data, grid_x, grid_y);
	return (FALSE);
}

void	move_player(t_data *data)
{
	t_point		new_player_pos;
	float		move_step;
	t_player	*player;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	if (player->rotation_angle < 0)
		player->rotation_angle += 2 * PI;
	if (player->rotation_angle > 2 * PI)
		player->rotation_angle -= 2 * PI;
	move_step = player->walk_direction * player->walk_speed;
	if (!move_step && player->side_direction)
		move_step = player->walk_speed;
	new_player_pos.x = player->pos.x + cos(
			rad_addition(player->rotation_angle, ((PI / 2)
				* player->side_direction))) * move_step;
	new_player_pos.y = player->pos.y + sin(
			rad_addition(player->rotation_angle, ((PI / 2)
				* player->side_direction))) * move_step;
	if (!wall_collision(data, new_player_pos.x, new_player_pos.y))
		player->pos = new_player_pos;
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	move_player(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
