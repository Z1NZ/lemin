# include "lemin.h"
# include <limits.h>

int		get_ants(char *line, t_data *data)
{
	int nb;
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])) == 0 || i >= 10)
			ft_exit(data);
		i++;
	}
	nb = ft_atoi(line);
	if (nb < 1 || nb > INT_MAX)
		ft_exit(data);
	else
		return(nb);
}
