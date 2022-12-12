/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:09:07 by mkorchi           #+#    #+#             */
/*   Updated: 2022/12/11 20:27:39 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAYCASTING_BONUS_H

# define RAYCASTING_BONUS_H

# define DR 0.0174533
# define FOV 1.0472
# define HALF_FOV 0.523599
 
// arrows
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define ESC 53
# define SPACE 49

# define SHOOT_KEY 1
# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13
# define M_KEY 46

# define FALSE 0
# define TRUE 1

# define HEIGHT 600
# define WIDTH 1200

# define TILE_SIZE 64

# define SCALE 20

# include "../parsing/parsing_bonus.h"
# include "../../minilibx/mlx.h"

typedef struct s_door {
	int		is_open;
	int		is_any_door_nearby;
	int		x;
	int		y;
	double	distance;
}	t_door;

typedef struct	s_img {
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
	t_img	door;
	t_img	door2;
	t_img	door3;
}	t_textures;


typedef struct s_animation {
	void	*f1;
	void	*f2;
	void	*f3;
	void	*f4;
	void	*f5;
	void	*f6;
	void	*f7;
	void	*f8;
	void	*f9;
	void	*f10;
	void	*f11;
	void	*f12;
	void	*f13;
	int		x;
	int		y;
}	t_animation;


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
	double	distV;
	double	distH;
	double	distF;
	int		h;
	char	horizontal_content;
	char	vertical_content;
	char	wall_hit_content;
	double	rx;
	double	ry;
	double	x0;
	double	y0;
	t_img	*img;
	int		texture_offsetx;
	int		texture_offsety;
	int		top_pixel;
	int		bot_pixel;
}	t_ray;


typedef struct s_player {
	t_point	pos;
	int		turn_direction;
	int		walk_direction;	
	int		side_direction;
	double	mouse_rotation; // rotation using mouse
	double	rotation_angle; 
	double	walk_speed;
	double	turn_speed;
	int		moves; // Player's moves
}	t_player;


typedef struct s_data
{
	t_textures	text;
	t_animation	frames;
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		img;
	t_pars		*pars;
	int			height;
	int			width;
	int			i;
	int			j;
	t_door		door;
	t_img		*current_door_frame;
	int			action_open;
	int			action_close;
	int			action_shoot;
	int			show_map;
}	t_data;


//			init.c
t_data		*init_data( t_pars *pars);
void		free_exit(t_data *data, int status);

//			actions.c
int			action(int keycode, t_data *data);
int			action_key_up(int keycode, t_data *data);
void		wall_collision(t_data *data, double pdx, double pdy, double move_step);

//			mlx_funs_bonus.c
void		update_screen(t_data *data);
void		move_player(t_data *data);

//			mouse_rotation.c && action.c
void		handle_arrows(int keycode, t_data *data, double rotation_speed);
int			mouse_rotation(int x, int y, t_data *data);

//			animation
void		animate(t_data *data);

//			weapon sprite
int			shoot_with_mouse(t_data *data);

//			img.c
void			create_new_img(t_data *data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_color(t_img *img, int x, int y);

//			extra_math.c
double 		rad2deg(double radians);
double		deg2rad(double degrees);
double		rad_addition(double rad1, double rad2);
double		calculate_distance(t_point a, t_point b);

//			draw.c
t_point		new_point(int x, int y);
void		draw_square(t_img *img, t_point pos, int color, int size);
void		draw_player(t_data *data);
void		dda(t_img *img, t_point a, t_point b, int color);

//			rays.c
void		cast_rays(t_data *data);
int			is_ray_facing_down(double ray_angle);
int			is_ray_facing_right(double ray_angle);


//			rays_intersection.c
void		init_ray(t_ray *ray);
void		find_first_vertical_intersection(t_data *data, t_ray *ray);
void		find_vertical_wall(t_data *data, t_ray *ray);
void		find_first_horizontal_intersection(t_data *data, t_ray *ray);
void		find_horizontal_wall(t_data *data, t_ray *ray);

//			mini_map_bonus.c
void		draw_minimap(t_data *data, int x, int y);
void		mini_map(t_data *data);


#endif