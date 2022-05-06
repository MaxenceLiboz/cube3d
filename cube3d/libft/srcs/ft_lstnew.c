/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:19:18 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 23:45:13 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list) * 1);
	if (!lst)
		return (0);
	lst->content = content;
	lst->len = ft_strlen(content);
	if (lst->content[lst->len - 1] == '\n')
		lst->len -= 1;
	lst->next = 0;
	return (lst);
}
