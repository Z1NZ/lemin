# include "lemin.h"

t_links	*add_top_link(t_links *links, t_links *src, t_data *data)
{
	t_links *tmp;

	if ((tmp = ft_memalloc(sizeof(t_links))) == NULL)
		ft_exit(data);
	tmp->lst = src->lst;
	tmp->next = links;
	return(tmp);
}