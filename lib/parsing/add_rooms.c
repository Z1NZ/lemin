#include "lemin.h"

void	add_rooms(t_data *data, t_lst *ptr)
{
	t_lst *tmp;

	tmp = data->lst;
	if (tmp == NULL)
	{
		data->lst = ptr;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ptr;
}
