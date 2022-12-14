/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:27:46 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/14 22:06:02 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	colors_checker(t_pars *pars, char *line)
{
	char	**s;

	s = my_split(line);
	if ((((ft_strncmp("F ", line, 2) == 0) && pars->floor == -1)
		|| ((ft_strncmp("C ", line, 2) == 0) && pars->ceilling == -1))
		&& pars->texture_checker < 4)
		ft_error("a texture is not set yet!\n");
	if (!s || !s[1] || s[2])
	{
		if (s)
			free_all(s);
		ft_error("Error in colors settings\n");
	}
	if ((ft_strncmp("F ", line, 2) == 0) && pars->floor == -1)
		pars->floor = set_colors(s[1]);
	else if ((ft_strncmp("C ", line, 2) == 0) && pars->ceilling == -1)
		pars->ceilling = set_colors(s[1]);
	else
	{
		if (s)
			free_all(s);
		ft_error("Textures settings aren't correct\n");
	}
	free_all(s);
}

int	check_line_helper(char *line, t_pars *pars)
{
	const char	*check[] = {"NO ", "SO ", "WE ", "EA "};
	static void	(*funcptr[5])(t_pars *, char *) = {north, south, west, east};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(check[i], line, 3) == 0)
		{
			funcptr[i](pars, line);
			pars->texture_checker++;
			return (1);
		}
		i++;
	}
	return (0);
}

// check wall in map's left
int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}
