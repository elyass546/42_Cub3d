/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:32:36 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/01 22:48:30 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

float	rad_addition(float rad1, float rad2)
{
	float	ret;

	ret = rad1 + rad2;
	if (ret < 0)
		ret += 2 * PI;
	if (ret > 2 * PI)
		ret -= 2 * PI;
	return (ret);
}

double	deg2rad(double degrees)
{
	return (degrees * (PI / 180));
}

double	rad2deg(double radians)
{
	return (radians * (180 / PI));
}

static float	ft_pow(float a)
{
	return (a * a);
}

float	calculate_distance(t_point a, t_point b)
{
	return (sqrt(ft_pow(b.x - a.x) + ft_pow(b.y - a.y)));
}
