#include "lemin.h"

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
