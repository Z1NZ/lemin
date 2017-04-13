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

void	init_tree(t_links *links, t_lst *end, int i)
{
	t_links *tmp;

	tmp = NULL;
	i++;
	while(links)
	{
		if (links->lst->value == 0)
		{
			if (tmp == NULL)
			{
				if(!(tmp = (t_links *)ft_memalloc(sizeof(t_links))))
				exit(-1);//free les structure
			}
			else
			{
				while(tmp)
					tmp = tmp->next;
				tmp = (t_links *)ft_memalloc(sizeof(t_links));/// check if null
			}
			tmp->lst = links->lst;
			tmp->lst->value = i;
			tmp->next = NULL;
		}
		links = links->next;
	}
	if (tmp && end->value == 0)
		init_tree(tmp, end, i);
	// free tmp
}



int		find_way(t_data *data)
{
	t_lst *start;
	t_lst *end;

	start = check_exist(data->start, data->lst);
	end = check_exist(data->end, data->lst);
	if (!start || !end)
		return (0);
	// printf("[%p]->%s  ---  [%p]->%s\n", end, end->name, start, start->name);
	start->value = 1;
	init_tree(start->links, end, 1);
	if (end->value != 0)
		printf("on a trouver une solution en couche [%d]\n", end->value);
	// print_lst(data->lst);
	return (end->value);
}