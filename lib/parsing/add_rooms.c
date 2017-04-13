
#include "lemin.h"

void	add_rooms(t_lst *src, t_lst *ptr)
{
	t_lst *tmp;

	tmp = src;

	if (tmp == NULL)
	{
		src = ptr;
		return ;
	}
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ptr;
}
