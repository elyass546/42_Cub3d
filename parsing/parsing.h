/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/20 18:52:13 by ie-laabb         ###   ########.fr       */
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
	int		id;
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

void	ft_error(char *str);
void	check_map(t_pars *pars);
void	north(t_pars *pars, char *str);
void	south(t_pars *pars, char *str);
void	west(t_pars *pars, char *str);
void	east(t_pars *pars, char *str);
void	player_pos(char *line, t_pars *pars, int player_y);
void	is_surrounded_by_walls(t_pars *data);
void	check_line(char *line, t_pars *pars);
void	map_line_counter(char *file, t_pars *pars);

#endif