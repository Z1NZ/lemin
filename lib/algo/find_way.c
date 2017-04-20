#include "lemin.h"

void		clean_list(t_links *tmp)
{
	t_links *ptr;

	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr);
		ptr = NULL;
	}
}

void		push_back(t_links *dest, t_links *src, t_data *data)
{
	if (dest)
	{
		while (dest->next)
			dest = dest->next;
		if ((dest->next = ft_memalloc(sizeof(t_links))) == NULL)
			ft_exit(data);
		dest->next->lst = src->lst;
		dest->next->next = NULL;
	}
}

t_links		*add_list(t_links *dest, t_links *src, t_data *data)
{
	while (src)
	{
		if (src->lst->value == 0)
		{
			if (!dest)
			{
				if ((dest = ft_memalloc(sizeof(t_links))) == NULL)
					ft_exit(data);
				dest->lst = src->lst;
				dest->next = NULL;
			}
			else
				push_back(dest, src, data);
		}
		src = src->next;
	}
	return (dest);
}

void		init_tree(t_lst *start, t_lst *end, t_data *data)
{
	t_links	*tmp_links;
	t_links	*links;
	int		i;

	i = 1;
	links = start->links;
	start->value = 1;
	while (links && end->value == 0)
	{
		tmp_links = NULL;
		i++;
		while (links)
		{
			if (links->lst->value == 0)
			{
				links->lst->value = i;
				tmp_links = add_list(tmp_links, links->lst->links, data);
			}
			links = links->next;
		}
		clean_list(links);
		links = tmp_links;
	}
}

int			find_way(t_data *data)
{
	t_lst	*start;
	t_lst	*end;
	t_links	*tmp;

	start = check_exist(data->start, data->lst);
	end = check_exist(data->end, data->lst);
	if (!start || !end)
		return (0);
	init_tree(start, end, data);
	if (end->value != 0)
	{
		tmp = discover_tree(end, data);
		ft_print_way(data, tmp);
		clean_list(tmp);
	}
	else
		ft_exit(data);
	data->status = 0;
	return (end->value);
}
