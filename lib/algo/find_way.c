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


void	init_tree(t_links *links, t_lst *end, int i)
{
	t_links *tmp;
	t_links *ptr;

	ptr = NULL;


	while(links && end->value == 0)
	{

		tmp = NULL;
		while(links)
		{
			i++;
			ft_putstr(links->lst->name);
			ft_putstr("\n");
			if (links->lst->value == 0)
			{
				ptr = tmp;
				if (tmp == NULL)
				{
					if(!(tmp = (t_links *)ft_memalloc(sizeof(t_links))))
					exit(-1);//free les structure
					tmp->lst = links->lst;
					tmp->lst->value = i;
					tmp->next = NULL;
				}
				else
				{
					while(ptr)
						ptr = ptr->next;
					ptr = (t_links *)ft_memalloc(sizeof(t_links));/// check if null
					ptr->lst = links->lst;
					ptr->lst->value = i;
					ptr->next = NULL;
				}
			}
			links = links->next;
		}
		// free links 
		links = tmp;
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
	init_tree(start->links, end, 1);
	if (end->value != 0)
		printf("on a trouver une solution en couche [%d]\n", end->value);
	// print_lst(data->lst);
	return (end->value);
}