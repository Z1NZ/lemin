/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 23:13:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/04 07:55:24 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"

void	print_lst(t_lst *lst)
{
	t_lst *tmp;
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		ft_printf("--[%s]--[%d]--[%d]--\n", tmp->rooms, tmp->y, tmp->x);
		tmp = tmp->next;
	}
}

int		get_rooms(char **line, t_rooms *r, t_lst **lst)
{
	ft_splitnb(*line, r);
	if (check_exist(r->room, *lst) == 1)
		*lst = add_rooms(*lst, r->room,r->y,r->x);
	if (*lst)
		print_lst(*lst);
	return(1);
}

int		next_step(char *line, t_lst *lst, t_rooms r)
{
	if ((check_room(line) == 0) && 
		((check_line(line) != 2) && (check_line(line) != 3)))
	{
		if (!lst)
			exit(0);	
		if (r.start == NULL || r.end == NULL)
			exit(0);
		if (get_links(line, lst) == 1)
			return (1);
		else
			exit (0);
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
	t_rooms	r;
	t_lst	*lst;
	char	*line;

	init_all(&line, &r, &lst);
	while (get_next_line(0, &line) > 0)
	{
		if (check_line(line) == 1)
			ft_printf("[COMMENTAIRES]\n");
		else if (r.index == 0 && (r.i = (get_ants(line)) > 0))
			r.index++;
		else if (r.index == 1 && check_line(line) != 1)
		{
			check_startend(&line, &r);
			if (check_room(line) == 1)
				get_rooms(&line, &r, &lst);
			if (next_step(line, lst, r) == 1)
				r.index++;
		}
		else if (r.index == 2 && check_line(line) != 1)
			get_links(line, lst);

		ft_printf("\n[%d]\n", r.index);
	}
}
