# include "lemin.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (s[i] && s[i] != c)
		i++;
	if (str[i] == c)
		return (str + i);
	return (NULL);
}
