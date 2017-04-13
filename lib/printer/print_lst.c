
# include "lemin.h"

void	print_lst(t_lst *lst)
{
	t_lst *tmp;
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		ft_putstr("\n[");
		ft_putstr(tmp->name);
		ft_putstr("] value = ");
		ft_putnbr(tmp->value);
		ft_putstr("]\n");
		tmp = tmp->next;
	}
}