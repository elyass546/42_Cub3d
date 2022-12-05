/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:32:42 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/05 16:33:46 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	free_parsing(t_pars *pars)
{
	if (pars->map)
		free_all(pars->map);
	if (pars->north)
		free(pars->north);
	if (pars->south)
		free(pars->south);
	if (pars->east)
		free(pars->east);
	if (pars->west)
		free(pars->west);
}
