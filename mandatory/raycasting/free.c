/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 21:53:56 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/10 11:14:06 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	free_exit(t_data *data, int status)
{
	if (status)
		ft_putstr_fd("ERROR\n", 2);
	(void) data;
	// if (data->mlx)
	// {
	// 	if (data->img.img)
	// 		mlx_destroy_image(data->mlx, data->img.img);
	// 	mlx_destroy_window(data->mlx, data->win);
	// 	destroy_textures(data);
	// 	free(data->mlx);
	// }
	// free(data);
	exit(status);
}

void	destroy_textures(t_data *data)
{
	if (data->pars->north)
		mlx_destroy_image(data->mlx, data->pars->north);
	if (data->pars->west)
		mlx_destroy_image(data->mlx, data->pars->west);
	if (data->pars->south)
		mlx_destroy_image(data->mlx, data->pars->south);
	if (data->pars->east)
		mlx_destroy_image(data->mlx, data->pars->east);
}
