# include "lemin.h"

void	clean_list(t_links *tmp)
{
	t_links *ptr;
	while(tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr);
		ptr = NULL;
	}
}
t_links 	*add_list(t_links *dest, t_links *src, t_data *data)
{
	t_links *ptr;

	ptr = dest;
	if (dest)
	{
		while(dest)
			dest = dest->next;
	}
	while(src)
	{
		if (src->lst->value == 0)
		{
			if (ptr == NULL)
			{
				if ((dest = ft_memalloc(sizeof(t_links))) == NULL)
					ft_exit(data);
				ptr = dest;
			}
			else
			{
				if ((dest = ft_memalloc(sizeof(t_links))) == NULL)
					ft_exit(data);
			}
			dest->lst = src->lst;
			dest->next = NULL;
			dest = dest->next;
		}
		src = src->next;
	}
	return (ptr);
}



void	init_tree(t_lst *start, t_lst *end, t_data *data)
{
	t_links *tmp_links;
	t_links *links;
	int i;

	i = 1;
	links = start->links;
	start->value = 1;
	while(links && end->value == 0)
	{
		tmp_links = NULL;
		i++;
		while(links)
		{
			printf("%s\n", links->lst->name);
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

t_links	*add_top_link(t_links *links, t_links *src, t_data *data)
{
	t_links *tmp;

	if ((tmp = ft_memalloc(sizeof(t_links))) == NULL)
		ft_exit(data);
	tmp->lst = src->lst;
	tmp->next = links;
	return(tmp);
}


t_links	*discover_tree(t_lst *end, t_data *data)
{
	int i;
	t_links *links;
	links = end->links;
	i = end->value;
	t_links *ptr;

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
	return(ptr);
}

int		find_way(t_data *data)
{
	t_lst *start;
	t_lst *end;
	t_links *tmp;

	start = check_exist(data->start, data->lst);
	end = check_exist(data->end, data->lst);
	if (!start || !end)
		return (0);
	init_tree(start, end, data);
	if (end->value != 0)
	{
		printf("\n[Solution couche -- > [%d] ]\n", end->value);
		tmp = discover_tree(end, data);
		while(tmp)
		{
			printf("[%s]->", tmp->lst->name);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else
	{
		printf("\n[Aucune solution Possible]\n");
		ft_exit (data);
	}
	return (end->value);
}
