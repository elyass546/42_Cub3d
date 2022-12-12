/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:32:42 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/12 17:29:46 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

void	free_parsing(t_pars *pars)
{
	if (!pars)
		return ;
	if (pars->map)
		free_all(pars->map);
	free(pars->north);
	free(pars->south);
	free(pars->east);
	free(pars->west);
	free(pars);
}
