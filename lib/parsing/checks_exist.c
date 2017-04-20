#include "lemin.h"

t_lst		*check_exist(char *s, t_lst *lst)
{
	while (lst)
	{
		if (ft_strcmp(lst->name, s) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
