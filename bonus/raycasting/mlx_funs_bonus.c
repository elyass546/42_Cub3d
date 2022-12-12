/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:43:33 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/12 15:53:18 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	*get_img(t_data *data, const char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx,
			path, &data->frames.x, &data->frames.y);
	return (img);
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	move_player(data);
	cast_rays(data);
	if (data->show_map)
	{
		mini_map(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	move_player(t_data *data)
{
	t_point		new_player_pos;
	double		move_step;
	t_player	*player;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	if (player->rotation_angle < 0)
		player->rotation_angle += 2 * M_PI;
	if (player->rotation_angle > 2 * M_PI)
		player->rotation_angle -= 2 * M_PI;
	move_step = player->walk_direction * player->walk_speed;
	if (player->side_direction)
		move_step = player->walk_speed;
	wall_collision(data,
		cos(rad_addition(player->rotation_angle, (M_PI_2
					* player->side_direction))),
		sin(rad_addition(player->rotation_angle, (M_PI_2
					* player->side_direction))),
		move_step);
}
