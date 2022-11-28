/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:00 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/28 18:58:25 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting_bonus.h"

int	wall_collision(t_data *data, float x, float y)
{
	float	angle;
	
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return TRUE;
	int grid_x = floor(x / TILE_SIZE);
	int grid_y = floor(y / TILE_SIZE);
	if (data->pars->map[grid_y][grid_x] != '0' && data->pars->map[grid_y][grid_x] != 'O')
		return TRUE;
	angle = data->player.rotation_angle;
	if (is_ray_facing_down(angle))
	{
		if (is_ray_facing_right(angle))
		{
			if (data->pars->map[grid_y - 1][grid_x] != '0' && data->pars->map[grid_y][grid_x - 1] != '0')
				return TRUE;
		}
		else
		{
			if (data->pars->map[grid_y - 1][grid_x] != '0' && data->pars->map[grid_y][grid_x + 1] != '0')
				return TRUE;
		}
	}
	else
	{
		if (is_ray_facing_right(angle))
		{
			if (data->pars->map[grid_y][grid_x - 1] != '0' && data->pars->map[grid_y + 1][grid_x] != '0')
				return TRUE;
		}
		else
		{
			if (data->pars->map[grid_y][grid_x + 1] != '0' && data->pars->map[grid_y + 1][grid_x] != '0')
				return TRUE;
		}
	}
	return FALSE;
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
	
	new_player_pos.x = player->pos.x + cos(player->rotation_angle) * move_step;
	new_player_pos.y = player->pos.y + sin(player->rotation_angle) * move_step;
	if (!wall_collision(data, new_player_pos.x, new_player_pos.y))
		player->pos = new_player_pos;
}

void	update_screen(t_data *data)
{
	create_new_img(data);
	// draw_walls(data);
	move_player(data);
	// draw_player(data);
	cast_rays(data);
	// mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

void	handle_arrows(int keycode, t_data *data, float rotation_speed)
{
	if (keycode == RIGHT)
		data->player.turn_direction = 1;
	else if (keycode == LEFT)
		data->player.turn_direction = -1;
	else if (keycode == UP)
	{
		data->player.moves++;
		data->player.walk_direction = 1;
	}
	else if (keycode == DOWN)
	{
		data->player.moves++;
		data->player.walk_direction = -1;
	}
}

void	handle_side_walk(int key, t_data *data)
{
	float	new_angle;

	if (key == A_KEY)
	{
		data->player.moves++;
		new_angle = data->player.rotation_angle - PI / 2;
		if ( new_angle < 0 )
			new_angle += 2 * PI;
	}
	else
	{
		data->player.moves++;
		new_angle = data->player.rotation_angle + PI / 2;
		if ( new_angle > 2 * PI)
			new_angle -= 2 * PI;
	}
	if ( !wall_collision(data, data->player.pos.x + cos(new_angle) * data->player.walk_speed,
		data->player.pos.y + sin(new_angle) * data->player.walk_speed))
	{
		data->player.pos.x += cos(new_angle) * data->player.walk_speed;
		data->player.pos.y += sin(new_angle) * data->player.walk_speed;
	}
}

// since W and S will behave like the arrows keys
// we just gonna use the same function
int	action(int keycode, t_data *data)
{
	if (keycode == ESC)
		free_exit(data, 0);
	else if (keycode >= LEFT && keycode <= UP)
		handle_arrows(keycode, data, 1);
	else if (keycode == W_KEY)
		handle_arrows(UP, data, 1);
	else if (keycode == S_KEY)
		handle_arrows(DOWN, data, 1);
	else if (keycode == A_KEY || keycode == D_KEY)
		handle_side_walk(keycode, data);
	else if (keycode == SPACE)
	{
		if (data->door.is_any_door_nearby)
		{
			if (data->pars->map[data->door.y][data->door.x] == 'O')
				data->pars->map[data->door.y][data->door.x] = 'D';
			else
				data->pars->map[data->door.y][data->door.x] = 'O';
		}
	}
	return (0);
}

int	action_key_up(int keycode, t_data *data)
{
	if (keycode == UP || keycode == DOWN || keycode == W_KEY || keycode == S_KEY)
		data->player.walk_direction = 0;
	else if (keycode == RIGHT || keycode == LEFT)
		data->player.turn_direction = 0;
	return (0);
}
