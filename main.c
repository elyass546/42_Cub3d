/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:42:35 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/14 18:43:00 by mkorchi          ###   ########.fr       */
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

	t_data	*data;

	data = init();

	
	mlx_hook(data->win, 02, 1L<<0 ,action, data);
	mlx_hook(data->win, 17, 0, destroy, data);
	mlx_loop(data->mlx);
	
	return (0);
}