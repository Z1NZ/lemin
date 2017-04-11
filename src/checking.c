/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 23:13:43 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/11 22:43:34 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lemin.h"
# include <limits.h>

int		get_ants(char *line)
{
	int nb;
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0 || i >= 10)
			exit(-1);///// free les structures
		i++;
	}
	nb = ft_atoi(line);
	ft_putnbr(nb);
	if (nb < 1 || nb > INT_MAX)// verifier les int max 
		exit(-1);////// free les structures
	else
		return(nb);
}

void	check_startend(char *line, t_rooms *r)
{
	if (check_line(line) == 2)
	{
		get_next_line(0, &line);
		if (check_room(line) == 1)
			r->start = ft_strdup(line);
	}
	else if (check_line(line) == 3)
	{
		get_next_line(0, &line);
		if (check_room(line) == 1)
			r->end = ft_strdup(line);
	}
}

void	check_links(char *line, t_lst *lst)
{
	char **link;

	link = ft_strsplit(line, '-');

	if (check_exist(link[0], lst) == 0)
	{
		ft_printf("-->[%s]<--\n", link[0]);
	}
	else
		ft_printf("ERROR");
	if (check_exist(link[1], lst) == 0)
		ft_printf("-->[%s]<--\n", link[1]);
	else
		ft_printf("ERROR");
}

int		check_line(char *line)
{
	if ((line[0]) && line[0] == '#' && line[1] != '#') 
		return (1);
	else if ((line[0] && line[1]) && line[0] == '#' && line[1] == '#')
	{
		if (ft_strcmp(line, "##start") == 0)
			return (2);
		else if (ft_strcmp(line, "##end") == 0)
			return (3);
		else
			return (1);
	}
	return (0);
}

int		check_exist(char *s, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->rooms, s) == 0)
			return(0);
		lst = lst->next;
	}
	return(1);
}
