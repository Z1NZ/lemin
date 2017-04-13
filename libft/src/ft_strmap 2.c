/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:00:47 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/30 01:32:08 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_memalloc(len + 1);
	if (str)
	{
		while (s[i])
		{
			str[i] = (f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
