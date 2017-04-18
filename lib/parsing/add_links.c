# include "lemin.h"

static void	add(t_lst *ptr1, t_lst *ptr2, t_data *data)
{
	t_links *tmp;

	tmp = ptr1->links;
	if (!ptr1->links)
	{
		if(!(ptr1->links = (t_links *)ft_memalloc(sizeof(t_links))))
			ft_exit(data);
		ptr1->links->lst = ptr2;
		ptr1->links->next = NULL;
	}
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		if(!(tmp->next = (t_links *)ft_memalloc(sizeof(t_links))))
			ft_exit(data);
		tmp->next->lst = ptr2;
		tmp->next->next = NULL;
	}
}

int		add_links(t_lst *ptr1, t_lst *ptr2, t_data *data)
{
	if (!ptr1 || !ptr2)
		return (0);
	add(ptr2, ptr1, data);
	add(ptr1, ptr2, data);
	return (1);
}
