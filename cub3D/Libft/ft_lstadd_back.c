/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:07:07 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/04 11:54:23 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	t_list	*mylist;

	if (!newl)
		return ;
	mylist = *lst;
	if (!mylist)
	{
		*lst = newl;
		return ;
	}
	mylist = ft_lstlast(*lst);
	mylist->next = newl;
}
