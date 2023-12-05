/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:33:07 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/04 11:53:57 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newl)
{
	if (!lst)
	{
		*lst = newl;
		return ;
	}
	if (!newl)
		return ;
	newl->next = *lst;
	*lst = newl;
}
