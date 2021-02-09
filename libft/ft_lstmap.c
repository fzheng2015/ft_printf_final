/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 21:25:54 by hzhou             #+#    #+#             */
/*   Updated: 2020/07/25 23:05:42 by hzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!f || !lst)
		return (0);
	if (!(new_list = ft_lstnew(f(lst->content))))
		return (0);
	lst = lst->next;
	new_elem = new_list;
	while (lst)
	{
		if (!(new_elem->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem = new_elem->next;
		lst = lst->next;
	}
	return (new_list);
}
