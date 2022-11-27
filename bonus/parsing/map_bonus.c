/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:45:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/26 23:02:11 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	check_textutres(t_pars *pars)
{
	if (pars->north && pars->south && pars->east && pars->west)
		return (1);
	return (0);
}

char	*skip_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (line + i);
		i++;
	}
	return (line + i);
}

int	check_if_filled(t_pars *pars)
{
	if (check_textutres(pars) && pars->ceilling != -1 && pars->floor != -1)
		return (1);
	return (0);
}

void	map_stocking(char *line, t_pars *pars)
{
	if (pars->map_end_index < pars->map_index)
	{
		pars->map[pars->map_end_index] = ft_strdup(line);
		pars->map_end_index++;
	}
	if (pars->map_end_index == pars->map_index)
		pars->map[pars->map_end_index] = NULL;
}

// storing map and textures
void	check_line(char *line, t_pars *pars)
{
	if (is_space(line[0]) && !pars->map[0] && !check_if_filled(pars))
		line = skip_spaces(line);
	if ((!line[0] || !line) && !pars->map[0])
		return ;
	if (!check_textutres(pars))
	{
		if (check_line_helper(line, pars))
			return ;
	}
	if (!check_if_filled(pars))
		colors_checker(pars, line);
	else
	{
		if (!line[0])
			return ;
		else if (!is_mapchar(line[0]))
			ft_error("Wrong element in map123\n");
		map_stocking(line, pars);
	}
}
