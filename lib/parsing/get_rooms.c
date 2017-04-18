# include "lemin.h"


static inline void fr_tmp_data(t_lst *tmp, t_data *data)
{
	free(tmp);
	ft_exit(data);
}

int		get_rooms(char *line, t_data *data)
{
	char **tab;
	t_lst *tmp;

	tmp = NULL;
	tab = ft_strsplit(line, ' ');
	if (tab_len(tab) == 3)
	{
		if (check_name(tab[0]) && ft_isdig_str(tab[1]) && ft_isdig_str(tab[2]))
		{
			if (!(tmp = ft_memalloc(sizeof(t_lst))))
				ft_exit(data);
			tmp->y = ft_atoi(tab[1]);
			tmp->x = ft_atoi(tab[2]);
			if (!(tmp->name = ft_strdup(tab[0])))
				fr_tmp_data(tmp, data);
			if (!check_exist(tab[0], data->lst))
				add_rooms(data, tmp);
			else
				fr_tmp_data(tmp, data);
		}
		else
			ft_exit(data);
	}
	ft_free_tab(tab);
	return(1);
}
