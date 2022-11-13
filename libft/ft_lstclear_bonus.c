/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:01:45 by mkorchi           #+#    #+#             */
/*   Updated: 2021/11/10 13:44:54 by mkorchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mylist;
	t_list	*next;

	if (lst == NULL && del == NULL)
		return ;
	mylist = *lst;
	while (mylist)
	{
		next = mylist->next;
		del(mylist->content);
		free(mylist);
		mylist = next;
	}
	*lst = NULL;
}
