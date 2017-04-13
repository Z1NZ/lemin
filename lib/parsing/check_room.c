
#include "lemin.h"

int		check_room(char *s)
{
	if (!s)
		return (0);
	if (!check_name(s))
		return (0);
	if ((count_char(s, ' ')) != 2)
		return(0);
	if ((check_nb(s)) == 0)
		return(0);
	return (1);
}
