/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:37:36 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/04 17:58:16 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main_bonus.h"

int	destroy(t_data *data)
{
	free_exit(data, 0);
	return (0);
}

int	render(t_data *data)
{
	static int	j = 0;
	static int	i = 0;

	if (data->action_open)
	{
		if (j < 10)
			data->current_door_frame = &data->text.door2;
		else if (j < 20)
			data->current_door_frame = &data->text.door3;
		else if (j < 30)
		{
			data->current_door_frame = &data->text.door;
			data->action_open = FALSE;
			data->pars->map[data->door.y][data->door.x] = 'O';
			j = 0;
		}
		j++;
	}
	else if (data->action_close)
	{
		data->pars->map[data->door.y][data->door.x] = 'D';
		if (i < 10)
			data->current_door_frame = &data->text.door3;
		else if (i < 20)
			data->current_door_frame = &data->text.door2;
		else if (i < 30)
		{
			data->current_door_frame = &data->text.door;
			data->action_close = FALSE;
			i = 0;
		}
		i++;
	}
	update_screen(data);
	if (data->action_shoot)
		shoot_with_mouse(data);
	data->i++;
	if (data->i >= 65)
	{
		data->i = 0;
		data->action_shoot = FALSE;	
	}
	data->player.turn_direction = 0;
	return (0);
}

int	mouse(int key, int x, int y, t_data *data)
{
	if (key == SHOOT_KEY && !data->action_shoot)
		data->action_shoot = TRUE;
	return (0);
}

int	main( int argc, char **argv )
{
	t_pars 	*pars;
	t_data	*data;
	if (argc != 2)
		ft_error("Wrong number of parameter\n");
	if (map_name_checker(argv[1]))
		ft_error("Map doesn't end with .cub\n");
	pars = parsing(argv[1]);
	data = init_data(pars);
	data->i = 0;
	mlx_mouse_hook(data->win, mouse, data);
	mlx_hook(data->win, 6, 0, mouse_rotation, data);
	mlx_hook(data->win, 2, 1L<<0 ,action, data);
	mlx_hook(data->win, 3, 1L<<1 ,action_key_up, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
	return (0);
}