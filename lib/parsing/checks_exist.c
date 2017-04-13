# include "lemin.h"
# include <limits.h>

int		check_exist(char *s, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, s) == 0)
			return(1);
		lst = lst->next;
	}
	return(0);
}
