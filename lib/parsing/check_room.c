
#include "lemin.h"

int		check_room(char *s)
{
	char	*name;

	name = NULL;
	if (!s)
		return (0);
	name = get_name(s);
	if (name == NULL)
		return (0);
	if ((count_char(s, ' ')) != 2)
		return(0);
	if ((check_nb(name)) == 0)
		return(0);
	return (1);
}
