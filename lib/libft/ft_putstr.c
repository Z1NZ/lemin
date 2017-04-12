# include "lemin.h"

void	ft_putstr(char const *s)
{
	write(1, s, ((int)ft_strlen(s)));
}
