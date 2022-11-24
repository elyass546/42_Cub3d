/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:10:30 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/24 23:06:17 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	animation_utiles(t_data *vars, int i)
{
	if (i < 5)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f1, 75, 0);
	else if (i < 10)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f2, 75, 0);
	else if (i < 15)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f3, 75, 0);
	else if (i < 20)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f4, 75, 0);
	else if (i < 25)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f5, 75, 0);
	else if (i < 30)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f6, 75, 0);
	else if (i < 35)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f7, 75, 0);
	else if (i < 40)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f8, 75, 0);
	else if (i < 45)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f9, 75, 0);
	else if (i < 50)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f10, 75, 0);
	else if (i < 55)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f11, 75, 0);
	else if (i < 60)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->frames.f12, 75, 0);
}

int	animation(t_data *vars)
{
	static int	i;

	animation_utiles(vars, i);
	if (i == 60)
		i = 0;
	i++;
	return (0);
}