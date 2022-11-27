/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:42:35 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/27 21:40:27 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

int	destroy(t_data *data)
{
	free_exit(data, 0);
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
	update_screen(data);
	mlx_hook(data->win, 02, 1L<<0 ,action, data);
	mlx_hook(data->win, 03, 1L<<1 ,action_key_up, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop(data->mlx);
	return (0);
}