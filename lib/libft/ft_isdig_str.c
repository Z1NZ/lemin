# include "lemin.h"

int		ft_isdig_str(char *ptr)
{
	unsigned int i;

	i = 0;

	while(ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (0);
		++i;
	}
	return (1);
}
