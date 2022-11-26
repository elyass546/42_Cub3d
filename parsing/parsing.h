/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/26 15:30:41 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

// get_next_line struct
typedef struct s_gnl {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_gnl;

typedef struct s_pars {
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	player_pos;
	int		player_x;
	int		player_y;
	int		map_index;
	int		map_end_index;
	int		floor;
	int		ceilling;
	int		col;
	int		row;
}			t_pars;

// ***************** parsing ************************* //

t_pars	*parsing(char *file);

char	*get_next_line(int fd);

char	**my_split(char const *s);

int		is_space(char c);
int		is_mapchar(char c);
int		set_colors(char *str);
int		is_playerchar(char c);
int		map_name_checker(char *str);
int		is_map(char *line, t_pars *pars);
int		check_line_helper(char *line, t_pars *pars);

void	ft_error(char *str);
void	check_map(t_pars *pars);
void	west(t_pars *pars, char *str);
void	east(t_pars *pars, char *str);
void	south(t_pars *pars, char *str);
void	north(t_pars *pars, char *str);
void	is_surrounded_by_walls(t_pars *data);
void	check_line(char *line, t_pars *pars);
void	colors_checker(t_pars *pars, char *line);
void	map_line_counter(char *file, t_pars *pars);
void	player_pos(char *line, t_pars *pars, int player_y);

#endif