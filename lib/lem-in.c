
# include "lemin.h"

int		next_step(char *line, t_lst *lst, t_rooms r)
{
	if ((check_room(line) == 0) && ((check_line(line) != 2) && (check_line(line) != 3)))
	{
		if (!lst || r.start == NULL || r.end == NULL)
			exit (0);// free memo
		if (get_links(line, lst) == 1)
			return (1);
		else
			exit (0);// free memo
	}
	return (0);
}

int 	get_links(char *line, t_lst *lst)
{
	if (count_char(line, '-') == 1)
		check_links(line, lst);
	else
		return (0);
	return (1);
}

int		main()
{
	char	*line;
	t_data	*data;

	if(!(data = ft_memalloc(sizeof(t_data))))
		return(0);
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (check_line(line) == 1)
			ft_putstr("[COMMENTAIRES]");
		else if (!CHECK_BIT(data.status, ANTS) && (data.nb_ant = get_ants(line)) > 0)
			data.status |= ANTS;
		else if (CHECK_BIT(data.status, ANTS) && (!CHECK_BIT(data.status, ROOMS)) && check_line(line) != 1)

			check_startend(line, data);


		



		else if (CHECK_BIT(data.status, ROOMS) && check_line(line) != 1)
			get_links(line, lst);
		free(line);
		ft_printf("\n[%d]\n", data.status);
	}
}
