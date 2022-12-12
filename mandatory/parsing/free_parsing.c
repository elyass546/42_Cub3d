/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <mkorchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:49 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/12/12 16:54:46 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// free all 
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
