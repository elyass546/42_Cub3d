/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:32:36 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/14 19:33:55 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycasting.h"

double	deg2rad(double degrees)
{
	return (degrees * (PI / 180));
}

double rad2deg(double radians)
{
	return (radians * (180 / PI));
}