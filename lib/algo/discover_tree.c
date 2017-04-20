#include "lemin.h"

t_links	*discover_tree(t_lst *end, t_data *data)
{
	int		i;
	t_links	*links;
	t_links	*ptr;

	links = end->links;
	i = end->value;
	if ((ptr = ft_memalloc(sizeof(t_links))) == NULL)
		ft_exit(data);
	ptr->lst = end;
	ptr->next = NULL;
	while (links && i > -1)
	{
		if (links->lst->value == i - 1)
		{
			ptr = add_top_link(ptr, links, data);
			links = links->lst->links;
			i--;
		}
		else
			links = links->next;
	}
	return (ptr);
}
