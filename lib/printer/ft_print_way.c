# include "lemin.h"

void	ft_advance_ants(t_links *ptr)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while(ptr)
	{
		value = ptr->lst->ant;	
		ptr->lst->ant = i;
		i = value;
		ptr = ptr->next;
	}
}

void	ft_color(int i)
{
	ft_putstr("\e[38;5;");
	ft_putnbr(120 + i + (i % 10));
	ft_putstr("m");
}
void finish(t_data *data, t_links *tmp)
{
	t_lst *end;
	t_links *ptr;



	ptr = tmp;
	end = check_exist(data->end, data->lst);
	while(end->ant)
	{
		while (ptr)
		{
			if (ptr->lst->ant)
			{
				ft_color(ptr->lst->ant);
				ft_putstr("L");
				ft_putnbr(ptr->lst->ant);
				ft_putstr("-");
				ft_putstr(ptr->lst->name);

				ft_putstr(STOP);
			}
			ptr = ptr->next;
		}
		ft_putstr("\n");
		ptr = tmp;
		ft_advance_ants(ptr);
	}
}


void 	ft_print_way(t_data *data, t_links *tmp)
{
	t_links *ptr;
	int		i;

	i = 0;
	ptr = tmp;
	while(i < data->nb_ant)
	{
		i++;
		if (ptr->lst->ant == 0)
			ptr->lst->ant = i;
		while (ptr)
		{

			if (ptr->lst->ant)
			{
				ft_color(ptr->lst->ant);
				ft_putstr("L");
				ft_putnbr(ptr->lst->ant);
				ft_putstr("-");
				ft_putstr(ptr->lst->name);
				ft_putstr(STOP);
			}
			ptr = ptr->next;
		}
		ft_putstr("\n");
		ptr = tmp;
		ft_advance_ants(ptr);
	}
	finish(data, tmp);
}
