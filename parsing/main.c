/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:47:34 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/11/17 17:18:38 by mkorchi          ###   ########.fr       */
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
	printf("\neast : %s\n", map->east);
	printf("player x : %d\n", map->player_x);
	printf("player y : %d\n", map->player_y);
	printf("player char : %c\n", map->player_pos);
	printf("player char : %d\n", map->col);
}