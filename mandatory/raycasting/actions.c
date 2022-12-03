/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/03 19:21:40 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	wall_collision(t_data *data, float pdx, float pdy, float move_step)
{
	int	x0;
	int	y0;

	if (pdx < 0)
		x0 = -40;
	else
		x0 = 40;
	
	if (pdy < 0)
		y0 = -40;
	else
		y0 = 40;
	int ipx = floor(data->player.pos.x / TILE_SIZE);
	int	ipy = floor(data->player.pos.y / TILE_SIZE);
	int	ipx_ = floor((data->player.pos.x + x0) / TILE_SIZE);
	int	ipy_ = floor((data->player.pos.y + y0) / TILE_SIZE);
	int	ipx_sub = floor((data->player.pos.x - x0) / TILE_SIZE);
	int	ipy_sub = floor((data->player.pos.y - y0) / TILE_SIZE);
	if (ipy_ < 0 || ipy_ > data->pars->row)
		return ;
	if (ipx_ < 0 || ipx_ > ft_strlen(data->pars->map[ipy_]))
		return ;
	if (data->player.walk_direction == -1)
	{
		if (data->pars->map[ipy][ipx_sub] == '0')
			data->player.pos.x += pdx * move_step;
		if (data->pars->map[ipy_sub][ipx] == '0')
			data->player.pos.y += pdy * move_step;
	}
	else
	{
		if (data->pars->map[ipy][ipx_] == '0')
			data->player.pos.x += pdx * move_step;
		if (data->pars->map[ipy_][ipx] == '0')
			data->player.pos.y += pdy * move_step;		
	}
}

void	move_player(t_data *data)
{
	t_point		new_player_pos;
	float		move_step;
	t_player	*player;
	float		angle;

	player = &data->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	if (player->rotation_angle < 0)
		player->rotation_angle += 2 * PI;
	if (player->rotation_angle > 2 * PI)
		player->rotation_angle -= 2 * PI;
	move_step = player->walk_direction * player->walk_speed;
	if (!move_step && player->side_direction)
		move_step = player->walk_speed;
	if (player->side_direction)
		move_step = player->walk_speed;
	wall_collision(data,
		cos(rad_addition(player->rotation_angle, ((PI / 2)
			* player->side_direction))),
		sin(
			rad_addition(player->rotation_angle, ((PI / 2)
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
