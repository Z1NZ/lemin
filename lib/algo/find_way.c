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


		ft_putstr("test");
		ft_putstr(links->lst->name);
		ft_putstr("\n");

		if (links->lst->value == 0)
		{
			ft_putstr("rrrrrrr");
			if (tmp == NULL)
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
				tmp = (t_links *)ft_memalloc(sizeof(t_links));
			}
			tmp->lst = links->lst;
			tmp->next = NULL;
			tmp->lst->value = i;
		}



		links = links->next;
	}
	i++;
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
	printf("[%p]  ---  [%p] %s\n", end, start, data->end);
	start->value = 1;
	init_tree(start->links, end, 1);
	if (end->value != 0)
		printf("on a trouver une solution en couche [%d]\n", end->value);
	return (end->value);
}