/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 04:57:46 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/11 22:42:27 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*add_rooms(t_lst *lst, char *str, int y, int x)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->rooms = ft_strdup(str);
		if (lst)
			tmp->next = lst;
		else
			tmp->next = NULL;
	}
	return (tmp);
}

int		check_room(char *s)
{
	char	*name;

	name = NULL;
	if (!s)
		return (0);
	name = get_name(s);
	if (name == NULL)
		return (0);
	if ((count_char(s, ' ')) != 2)
		return(0);
	if ((check_nb(name)) == 0)
		return(0);
	return (1);
}

int		ft_splitnb(char *s, t_rooms *r)
{
	char *name;

	name = get_name(s);

	r->room = ft_strsub(s, 0, (size_t)(name - s));
	r->y = ft_atoi(name);
	r->x = ft_atoi(name + ft_len_int(r->y) + 1);
	return (1);
}
