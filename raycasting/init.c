/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:16:53 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/14 18:43:09 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../main.h"

void	free_exit(t_data *data, int status)
{
	if (status)
		ft_putstr_fd("ERROR\n", 2);
	if (data->mlx)
	{
		if (data->img.img)
			mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	// free_map(data->map);
	free(data);
	exit(status);
}

void	init_player_config()
{
	
}

t_data	*init( void )
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->img.img = NULL;
	create_img(data);
	return (data);
}