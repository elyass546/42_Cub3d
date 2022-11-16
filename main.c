/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:42:35 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/16 15:53:09 by mkorchi          ###   ########.fr       */
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
	(void) argc;
	(void) argv;
	t_pars 	*pars;
	t_data	*data;

	pars = parsing("map.cub");
	pars->col = 23; // to remove later
	data = init_data(pars);
	update_screen(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	
	printf("height of screen : %d\n", pars->row);
	printf("width of screen : %d\n", pars->col);
		
	mlx_hook(data->win, 02, 1L<<0 ,action, data);
	mlx_hook(data->win, 03, 1L<<1 ,action_key_up, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop(data->mlx);	
	return (0);
}