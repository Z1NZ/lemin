/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:20:50 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/29 06:10:40 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_start(t_conv *t)
{
	t->i = 0;
	t->j = 0;
}

char	next_conv(const char *s, int i)
{
	int		j;
	char	*conv;

	j = 0;
	conv = "sdiuc";
	while (conv[j] != '\0')
	{
		if (s[i] == conv[j])
			return (conv[j]);
		j++;
	}
	return (0);
}

int		ft_len_int(long int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	init(t_conv *t)
{
	t->len_return = 0;
}
