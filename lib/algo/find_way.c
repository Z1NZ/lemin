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
t_links 	*add_list(t_links *dest, t_links *src, int i)
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
			// printf("[%s][%d]\n", dest->lst->name, i);
		if (src->lst->value == 0)
		{
		// printf("[[%s]]\n"
			src->lst->value = i;
			dest = ft_memalloc(sizeof(t_links));
			dest->lst = src->lst;
			dest->next = NULL;
			dest = dest->next;
		}
		src = src->next;
	}
	return (ptr);
}



void	init_frist_node(t_links *links, int i)
{
	t_links *ptr;

	ptr = links;
	while(ptr)
	{
		ptr->lst->value = i;
		ptr = ptr->next;
	}
}

void	init_tree(t_links *links, t_lst *end, int i)
{
	t_links *tmp;
	while(links && end->value == 0)
	{
		tmp = NULL;
		i++;
		while(links)
		{
			// ft_putstr("\n");
			printf("%s[%s]%s->",RED,(links->lst->name),STOP);
			if (links->lst->value == 0 || links->lst->value == i - 1)
			{
				tmp = add_list(tmp, links->lst->links, i);
			}
			links = links->next;
		}
		links = tmp;
		// free links 
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
	init_frist_node(start->links, 2);
	printf("%s[%s]%s->",BOLD, start->name, STOP);
	init_tree(start->links, end, 2);
	printf("%s[%s]%s",BLUE, end->name, STOP);
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