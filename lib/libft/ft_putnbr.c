
# include "lemin.h"
#include <unistd.h>

void	ft_putnbr(int n)
{
	long int	u_nbr;

	u_nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr((int)(u_nbr / 10));
	ft_putchar(u_nbr % 10 + '0');
}
