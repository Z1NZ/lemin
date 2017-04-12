
#include "lemin.h"

int		ft_splitnb(char *s, t_rooms *r)
{
	char *name;

	name = get_name(s);
	r->room = ft_strsub(s, 0, (size_t)(name - s));
	r->y = ft_atoi(name);
	r->x = ft_atoi(name + ft_len_int(r->y) + 1);
	return (1);
}
