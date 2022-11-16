/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:42:35 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/16 15:20:32 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

// int	destroy(t_data *data)
// {
// 	free_exit(data, 0);
// 	return (0);
// }

int	main( int argc, char **argv )
{
	(void) argc;
	(void) argv;
	t_pars 	*map;
	// t_data	*data;

	map = parsing("map.cub");
	for (int i = 0; map->map[i]; i++)
		printf("index : %s\n", map->map[i]);
	// data = init();
	// data->
	
	// mlx_hook(data->win, 02, 1L<<0 ,action, data);
	// mlx_hook(data->win, 17, 0, destroy, data);
	// mlx_loop(data->mlx);
	
	return (0);
}