#include "lemin.h"

int		check_nb(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == ' ' || ft_isdigit(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}