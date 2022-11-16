/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:09:07 by mkorchi           #+#    #+#             */
/*   Updated: 2022/11/15 15:18:51 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H

# define RAYCASTING_H

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533
 

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define ESC 53

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

# define FALSE 0
# define TRUE 1

# define HEIGHT 512
# define WIDTH 1024

# define TILE_SIZE 64

# include "../parsing/parsing.h"
# include <mlx.h>

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
	int		turn_direction;
	int		walk_direction;	
	float	rotation_angle; 
	float	walk_speed;
	float	turn_speed;
}	t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	t_pars		*pars;
	int			height;
	int			width;
}	t_data;


//			init.c
t_data		*init( int x, int y );
void		free_exit(t_data *data, int status);


//			actions.c
int			action(int keycode, t_data *data);


//			img.c
void		create_img(t_data *data);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);


//			extra_math.c
double 		rad2deg(double radians);
double		deg2rad(double degrees);

//			draw.c
void		draw_square(t_img *img, int x, int y, int color);
void		draw_walls(t_data *data);



#endif