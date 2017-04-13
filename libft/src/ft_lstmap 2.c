/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 12:49:18 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/21 12:50:22 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*cpy_olist;
	t_list	*new_list;
	t_list	*cpy_new_list;

	if (!lst || !f)
		return (NULL);
	cpy_olist = f(lst);
	cpy_new_list = ft_lstnew(cpy_olist->content, cpy_olist->content_size);
	if (cpy_new_list == NULL)
		return (NULL);
	new_list = cpy_new_list;
	while (lst->next)
	{
		cpy_olist = f(lst->next);
		cpy_new_list->next = ft_lstnew(cpy_olist->content,
				cpy_olist->content_size);
		if (cpy_new_list == NULL)
			return (NULL);
		lst = lst->next;
		cpy_new_list = cpy_new_list->next;
	}
	return (new_list);
}
