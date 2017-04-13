/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:27:56 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 10:18:58 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_isnegative(long int n, int *negative, unsigned long int *min)
{
	if (n < 0)
	{
		*min = n * (-1);
		*negative = 1;
	}
	else
		*min = n;
}

char		*ft_itoa(long long int n)
{
	long long int		tmp;
	int					len;
	int					negative;
	char				*str;
	unsigned long int	min;

	len = 2;
	negative = 0;
	itoa_isnegative(n, &negative, &min);
	tmp = min;
	while (tmp /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		exit(0);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = min % 10 + '0';
		min = min / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
