/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/04 21:11:22 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	wall_collision(t_data *data, double pdx, double pdy, double move_step)
{
	int	old_px;
	int	old_py;
	int	new_px;
	int	new_py;

	old_px = floor(data->player.pos.x / TILE_SIZE);
	old_py = floor(data->player.pos.y / TILE_SIZE);
	new_px = floor((data->player.pos.x + (pdx * move_step)) / TILE_SIZE);
	new_py = floor((data->player.pos.y + (pdy * move_step)) / TILE_SIZE);
	if (data->pars->map[new_py][old_px] == '0')
		data->player.pos.y += pdy * move_step;
	if (data->pars->map[old_py][new_px] == '0')
		data->player.pos.x += pdx * move_step;
}

void	move_player(t_data *data)
{
	t_point		new_player_pos;
	double		move_step;
	t_player	*player;
	double		angle;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	if (player->rotation_angle < 0)
		player->rotation_angle += 2 * M_PI;
	if (player->rotation_angle > 2 * M_PI)
		player->rotation_angle -= 2 * M_PI;
	move_step = player->walk_direction * player->walk_speed;
	if (!move_step && player->side_direction)
		move_step = player->walk_speed;
	if (player->side_direction)
		move_step = player->walk_speed;
	wall_collision(data,
		cos(rad_addition(player->rotation_angle, (M_PI_2
			* player->side_direction))),
		sin(rad_addition(player->rotation_angle, (M_PI_2
			* player->side_direction))),
		move_step);
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	move_player(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
