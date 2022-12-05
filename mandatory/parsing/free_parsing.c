/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:49 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/05 16:31:51 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// free all 
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
