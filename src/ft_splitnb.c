/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 04:57:46 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 07:54:58 by aboudjem         ###   ########.fr       */
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
	int i;
	i = 0;
	if (!s)
		return (0);
	i = len_str(s);
	if (i == 0)
		return (0);
	if ((count_char(s, ' ')) != 2)
		return(0);
	if ((check_nb(s + i)) == 0)
		return(0);
	return (1);
}

int		ft_splitnb(char *s, t_rooms *r)
{
	int i;

	i = len_str(s);

	r->room = ft_strsub(s, 0, (size_t)i);
	r->y = ft_atoi(s+i);
	r->x = ft_atoi(s+(i + ft_len_int(r->y) + 1));
	return (1);
}
