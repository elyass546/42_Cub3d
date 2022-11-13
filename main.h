/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:17:19 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/13 21:46:01 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H


# define MAIN_H

# include "libft/libft.h"

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

# define FALSE 0
# define TRUE 1

# define HEIGHT 512
# define WIDTH 1024

# define TILE 64

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point {
	float	x;
	float	y;
}	t_point;


typedef struct s_ray
{

}	t_ray;


typedef struct s_player {
	t_point	pos;
	float	pdx;
	float	pdy;
	float	angle;
	float	fov;
}	t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	//should add map here t_map *map --  when ie-laabb is done
}	t_data;



#endif