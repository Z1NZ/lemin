
# include "lemin.h"

void	print_lst_links(t_lst *lst)
{
	t_lst *tmp;
	t_links *tmp2;
	tmp = NULL;
	tmp = lst;
	while(tmp)
	{
		ft_putstr("\n[");
		ft_putstr(tmp->name);
		ft_putstr("] value = ");
		ft_putnbr(tmp->value);
		ft_putstr("] ->");
		tmp2 = tmp->links;
		while(tmp2)
		{
			ft_putstr(tmp2->lst->name);
			ft_putstr("->");
			tmp2 = tmp2->next;
		}
		ft_putstr("\n");
		tmp = tmp->next;
	}
}