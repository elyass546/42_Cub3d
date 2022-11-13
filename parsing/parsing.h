#ifndef PARSING_H
#define PARSING_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include "../libft/libft.h"

typedef struct s_gnl {
	char	c;
	char	*str;
	int		read_return;
	char	*temp;
}				t_gnl;

struct s_pars
{
    char	*north;
    char	*south;
    char	*west;
    char	*east;
    int		floor;
    int		ceilling;
    char	player_pos;
    char	**map;
	int		id;
}   t_pars;


// ***************** parsing *************************

void	parsing(char *file);
char	*get_next_line(int fd);
char	**my_split(char const *s);

#endif