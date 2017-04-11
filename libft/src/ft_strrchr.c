/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:01:33 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/21 11:26:54 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char*)s;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
			return (str + len);
		else
			len--;
	}
	return (NULL);
}
