#include "lemin.h"

char	*get_name(char *s)
{
	int i;

	i = 0;
	if (s[0] == '#' || s[0] == 'L')
		return(0);
	while(s[i] != ' ' && s[i] != '\0')
		i++;
	if (i == 0)
		return(NULL);
	return(s + i);
}