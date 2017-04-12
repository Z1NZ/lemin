#include "lemin.h"

int		check_name(char *s)
{
	int i;

	i = 0;
	if (s[0] == '#' || s[0] == 'L')
		return(0);
	while(s[i] != ' ' && s[i] != '\0')
	{
		if (s[i] == '-')
			return(0);
		i++;
	}
	if (i == 0)
		return(0);
	return(1);
}