# include "lemin.h"

int		get_rooms(char *line, t_data *data)
{
	char **tab;
	lst *tmp;


	if (count_char(line, ' ') != 2)
		exit(-1);/// free les structure
	if (tab = ft_strsplit(line, ' '))
	{
		if (check_name(tab[0]) && ft_isdig_str(tab[1]) && ft_isdig_str(tab[2]))
		{
			if (!(tmp = ft_memalloc(sizeof(lst))))
				exit(-1);/// free les structure
				tmp->y = ft_atoi(tab[1]);
				tmp->x = ft_atoi(tab[2]);
				if (tmp->name = ft_strdup(tab[0]))
					exit(-1); // free les structure
			if (!check_exist(tab[0], data->lst))
				add_rooms(lst, r->room,r->y,r->x);
			else
				// free la tmp;

		}
	}
	ft_free_tab(tab);

	if (data->lst)
		print_lst(data->lst);
	return(1);
}
