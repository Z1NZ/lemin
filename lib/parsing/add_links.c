# include "lemin.h"

static void	add(t_lst *ptr1, t_lst *ptr2)
{
	t_links *tmp;

	tmp = ptr1->links;
	if (!ptr1->links)
	{
		if(!(ptr1->links = (t_links *)ft_memalloc(sizeof(t_links))))
			exit(-1);//free les structure
		ptr1->links->lst = ptr2;
		ptr1->links->next = NULL;
	}
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		if(!(tmp->next = (t_links *)ft_memalloc(sizeof(t_links))))
			exit(-1);//free les structure
		tmp->next->lst = ptr2;
		tmp->next->next = NULL;
	}
}

int		add_links(t_lst *ptr1, t_lst *ptr2)
{
	if (!ptr1 || !ptr2)
		return (0);

	add(ptr2, ptr1);
	add(ptr1, ptr2);
	return (1);
}