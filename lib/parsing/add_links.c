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
	}
	else
	{
		while(ptr1->links)
			ptr1->links = ptr1->links->next;
		if(!(ptr1->links = (t_links *)ft_memalloc(sizeof(t_links))))
		{
			//free les structure
			exit(-1);
		}
	}
	ptr1->links->lst = ptr2;
	ptr1->links->next = NULL;
}

int		add_links(t_lst *ptr1, t_lst *ptr2)
{
	if (!ptr1 || !ptr2)
		return (0);
	add(ptr1, ptr2);
	add(ptr2, ptr1);
	return (1);
}