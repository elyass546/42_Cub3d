/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:09:07 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/10 21:44:56 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define DR 0.0174533
# define FOV 1.0472
# define HALF_FOV 0.523599

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define ESC 53
# define SPACE 49

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13

# define FALSE 0
# define TRUE 1

# define HEIGHT 600
# define WIDTH 1200

# define TILE_SIZE 64

# include "../parsing/parsing.h"
# include "../../minilibx/mlx.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point {
	double	x;
	double	y;
}	t_point;

typedef struct s_textures {
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_textures;

typedef struct s_wall {
	double			wall_h;
	int				wall_strip_height;
	int				top_pixel;
	int				bot_pixel;
	int				texture_offsetx;
	t_img			*img;
	int				distance_from_top;
	int				texture_offsety;
	unsigned int	color;
}	t_wall;

typedef struct s_ray
{
	double	ray_angle;
	int		was_hit_vertical;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	t_point	vertical_hit;
	t_point	horizontal_hit;
	t_point	wall_hit;
	double	dist_v;
	double	dist_h;
	double	dist_f;
	int		h;
	double	rx;
	double	ry;
	double	x0;
	double	y0;
}	t_ray;

typedef struct s_player {
	t_point	pos;
	int		turn_direction;
	int		walk_direction;
	int		side_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
}	t_player;

typedef struct s_data
{
	t_textures	text;
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	t_pars		*pars;
	int			height;
	int			width;
	int			i;
}	t_data;

//				init.c
t_data			*init_data( t_pars *pars);

//				free.c
void			free_exit(t_data *data, int status);

//				actions.c
int				action(int keycode, t_data *data);
int				action_key_up(int keycode, t_data *data);
void			update_screen(t_data *data);

//				mouse_rotation.c && action.c
void			handle_arrows(int keycode, t_data *data);

//				img.c
void			create_new_img(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_color(t_img *img, int x, int y);

//				extra_math.c
double			rad2deg(double radians);
double			deg2rad(double degrees);
double			rad_addition(double rad1, double rad2);
double			calculate_distance(t_point a, t_point b);

//				draw.c
t_point			new_point(int x, int y);
void			draw_square(t_img *img, t_point pos, int color, int size);
void			draw_wall(t_data *data, t_ray *ray);
void			draw_walls(t_data *data);
void			draw_player(t_data *data);
void			dda(t_img *img, t_point a, t_point b, int color);

//				rays.c
void			cast_rays(t_data *data);
int				is_ray_facing_down(double ray_angle);
int				is_ray_facing_right(double ray_angle);

//				rays_intersection.c
void			init_ray(t_ray *ray);
int				find_vertical_wall_helper(int mx, int my,
					t_data *data, t_ray *ray);
int				find_horizontal_wall_helper(int mx, int my,
					t_data *data, t_ray *ray);
void			find_first_vertical_intersection(t_data *data, t_ray *ray);
void			find_vertical_wall(t_data *data, t_ray *ray);
void			find_first_horizontal_intersection(t_data *data, t_ray *ray);
void			find_horizontal_wall(t_data *data, t_ray *ray);

#endif