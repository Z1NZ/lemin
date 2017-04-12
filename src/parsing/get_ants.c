# include "lemin.h"
# include <limits.h>

int		get_ants(char *line)
{
	int nb;
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0 || i >= 10)
			exit(-1);///// free les structures
		i++;
	}
	nb = ft_atoi(line);
	ft_putnbr(nb);
	if (nb < 1 || nb > INT_MAX)// verifier les int max 
		exit(-1);////// free les structures
	else
		return(nb);
}