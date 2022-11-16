/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:21:05 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/16 15:37:53 by ie-laabb         ###   ########.fr       */
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
	int		map_index;
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

int		is_mapchar(char c, t_pars *pars);

void	ft_error(char *str);
#endif