# include "lemin.h"

int		get_rooms(char *line, t_data *data)
{
	char **tab;
	t_lst *tmp;

	tmp = NULL;
	if (count_char(line, ' ') != 2)
		exit(-1);/// free les structure
	if ((tab = ft_strsplit(line, ' ')))
	{
		if (!tab[1] || !tab[2])
			exit (-1);//free struct
		if (check_name(tab[0]) && ft_isdig_str(tab[1]) && ft_isdig_str(tab[2]))
		{
			if (!(tmp = ft_memalloc(sizeof(t_lst))))
				exit(-1);/// free les structure
			tmp->y = ft_atoi(tab[1]);
			tmp->x = ft_atoi(tab[2]);
			if (!(tmp->name = ft_strdup(tab[0])))
			{
				free(tmp);
					exit(-1); // free les structure
				}
				if (!check_exist(tab[0], data->lst))
					add_rooms(data, tmp);
				else
				{
					free(tmp);
					exit(-1);
				}

			}
			else
			{
				free(tmp);
			exit(-1); // free les structure
		}
	}
	ft_free_tab(tab);
	// if (data->lst) // debug
		// print_lst(data->lst);
	return(1);
}
