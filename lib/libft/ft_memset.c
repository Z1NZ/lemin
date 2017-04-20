#include "lemin.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = b;
	while (len > i)
	{
		str[i] = (char)c;
		i++;
	}
	b = str;
	return (b);
}
