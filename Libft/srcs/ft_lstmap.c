/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:56:55 by yomai-va          #+#    #+#             */
/*   Updated: 2018/11/29 18:37:05 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*first;

	list = f(lst);
	first = list;
	if ((!f) || (!lst))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
			return (NULL);
		list = list->next;
	}
	return (first);
}
