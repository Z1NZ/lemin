
#include "lemin.h"

t_lst	*add_rooms(t_lst *lst, data->lst)
{
	t_lst	*tmp;

	if ((tmp = ft_memalloc(sizeof(t_lst))))
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
