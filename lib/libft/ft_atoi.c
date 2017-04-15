# include "lemin.h"

static int	neg_handling(int neg, int nbr)
{
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
	return (0);
}

int			ft_atoi(const char *str)
{
	int i;
	int nbr;
	int neg;

	nbr = 0;
	i = 0;
	neg = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		nbr *= 10;
		nbr += (int)(str[i] - '0');
		i++;
	}
	return (neg_handling(neg, nbr));
}
