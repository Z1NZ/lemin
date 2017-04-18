# include "lemin.h"

 // ParcoursLargeur(Graphe G, Sommet s):
 //       f = CreerFile();
 //       f.enfiler(s);
 //       marquer(s);
 //       tant que la file est non vide
 //                s = f.defiler();
 //                afficher(s);
 //                pour tout voisin t de s dans G
 //                         si t non marqué
 //                                 f.enfiler(t);
 //                                 marquer(t);


// typedef struct			s_links
// {
// 	struct s_lst		*lst;
// 	struct s_links		*next;
// }						t_links;

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
t_links 	*add_list(t_links *dest, t_links *src)
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
				dest = ft_memalloc(sizeof(t_links));
				ptr = dest;
			}
			else
				dest = ft_memalloc(sizeof(t_links));
			dest->lst = src->lst;
			dest->next = NULL;
			dest = dest->next;
		}
		src = src->next;
	}
	printf("%p\n", ptr);
	return (ptr);
}



void	init_tree(t_lst *start, t_lst *end)
{
	t_links *tmp_links;
	t_links *links;
	int i;

	i = 0;
	links = start->links;
	while(links && end->value == 0)
	{
		tmp_links = NULL;
		i++;
		while(links)
		{

			if (links->lst->value == 0)
			{
				printf(RED"[%s]==\n"STOP, links->lst->name);
				links->lst->value = i;
				tmp_links = add_list(tmp_links, links->lst->links);
			}
			links = links->next;
		}
		links = tmp_links;
	}
}



int		find_way(t_data *data)
{
	t_lst *start;
	t_lst *end;

	start = check_exist(data->start, data->lst);
	end = check_exist(data->end, data->lst);
	if (!start || !end)
		return (0);
	start->value = 1;
	// printf("%s[%s]%s->",BOLD, start->name, STOP);
	init_tree(start, end);
	// printf("%s[%s]%s",BLUE, end->name, STOP);
	printf("\n[%d]\n", end->value);
	if (end->value != 0)
		printf("\n[Solution couche -- > [%d] ]\n", end->value);
	else
	{
		printf("\n[Aucune solution Possible]\n");
		exit (1);//free
	}

	// print_lst(data->lst);
		// ft_putstr("\n==============================ROOM avec les links===============================\n");
		// print_lst_links(data->lst);
	return (end->value);
}
