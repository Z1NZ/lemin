# include "lemin.h"

int		get_rooms(char *line, t_rooms *r, t_lst *lst)
{
	ft_splitnb(line, r);
	if (check_exist(r->room, lst) == 1)
		lst = add_rooms(lst, r->room,r->y,r->x);
	if (lst)
		print_lst(lst);
	return(1);
}
