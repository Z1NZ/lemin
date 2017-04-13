/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_of_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 02:31:04 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/30 02:31:06 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_of_char(const char *str, char c)
{
	int	i;
	int	nb;
	int len;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
		{
			nb++;
		}
		i++;
	}
	return (nb);
}
