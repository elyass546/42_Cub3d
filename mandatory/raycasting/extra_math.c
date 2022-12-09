/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:32:36 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/09 21:55:27 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	rad_addition(double rad1, double rad2)
{
	double	ret;

	ret = rad1 + rad2;
	if (ret < 0)
		return (ret + 2 * M_PI);
	if (ret > 2 * M_PI)
		return (ret - 2 * M_PI);
	return (ret);
}

double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180));
}

double	rad2deg(double radians)
{
	return (radians * (180 / M_PI));
}

static double	ft_pow(double a)
{
	return (a * a);
}

double	calculate_distance(t_point a, t_point b)
{
	return (sqrt(ft_pow(b.x - a.x) + ft_pow(b.y - a.y)));
}
