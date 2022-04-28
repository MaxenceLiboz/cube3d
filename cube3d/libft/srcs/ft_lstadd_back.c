/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:44:04 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 15:11:54 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stdio.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	new->next = 0;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
