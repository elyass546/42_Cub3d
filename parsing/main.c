/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:34 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/16 19:33:38 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int ac, char **av)
{
	t_pars	*map;

	if (ac != 2)
		ft_error("Wrong number of parameter\n");
	if (map_name_checker(av[1]))
		ft_error("Map doesn't end with .cub\n");
	map = parsing(av[1]);
	for (int i = 0; map->map[i]; i++)
		printf("%s\n", map->map[i]);
	printf("\n%s\n", map->east);
	// printf("\n%c\n", map->player_pos);
}