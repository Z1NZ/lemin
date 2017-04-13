# include "lemin.h"

static inline void	add(t_lst *ptr1, t_lst *ptr2)
{
	t_links *tmp;

	tmp = ptr1->links;
	if (!ptr1->links)
	{
		if(!(ptr1->links = (t_links *)ft_memalloc(sizeof(t_links))))
		{
			//free les structure
			exit(-1);
		}
			ptr1->links->lst = ptr2;
			ptr1->links->next = NULL;
	}
	else
	{
		while(ptr1->links->next)
			ptr1->links = ptr1->links->next;
		if(!(ptr1->links->next = (t_links *)ft_memalloc(sizeof(t_links))))
		{
			//free les structure
			exit(-1);
		}
		ptr1->links->next->lst = ptr2;
		ptr1->links->next->next = NULL;
	}
}

int		add_links(t_lst *ptr1, t_lst *ptr2)
{
	if (!ptr1 || !ptr2)
		return (0);
	add(ptr2, ptr1);
	add(ptr1, ptr2);
	print_lst_links(ptr1);
	ft_putstr("----------------\n");
	print_lst_links(ptr2);	
	return (1);
}