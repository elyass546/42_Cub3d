/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:42:35 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/03 16:15:15 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	destroy(t_data *data)
{
	free_exit(data, 0);
	return (0);
}

int	render(t_data *data)
{
	update_screen(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pars	*pars;
	t_data	*data;

	if (argc != 2)
		ft_error("Wrong number of parameter\n");
	if (map_name_checker(argv[1]))
		ft_error("Map doesn't end with .cub\n");
	pars = parsing(argv[1]);
	data = init_data(pars);
	mlx_hook(data->win, 2, 1L << 0, action, data);
	mlx_hook(data->win, 3, 1L << 1, action_key_up, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
	return (0);
}
