# include "lemin.h"

static inline void	add(t_lst *ptr1, t_lst *ptr2)
{
	t_links *tmp;

	tmp = ptr1->links;
	if (!tmp)
	{
		if(!(tmp = (t_links *)ft_memalloc(sizeof(t_links))))
		{
			//free les structure
			exit(-1);
		}
	}
	else
	{
		while(tmp)
			tmp = tmp->next;
		if(!(tmp = (t_links *)ft_memalloc(sizeof(t_links))))
		{
			//free les structure
			exit(-1);
		}
	}
	tmp->lst = ptr2;
	tmp->next = NULL;
}

int		add_links(t_lst *ptr1, t_lst *ptr2)
{
	if (ptr1 || ptr2)
		return (0);
	add(ptr1, ptr2);
	add(ptr2, ptr1);
	return (1);
}