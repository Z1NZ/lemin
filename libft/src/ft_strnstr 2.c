/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:19:22 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/30 01:33:06 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*cpy;
	char	*buf;
	size_t	length;

	buf = (char *)(big + len);
	length = ft_strlen(little);
	cpy = (char *)big;
	if (!little || !length)
		return ((char *)big);
	while ((cpy = ft_strchr(cpy, *little)) && cpy <= buf)
	{
		if ((cpy + length <= buf) && !ft_strncmp(cpy, little, length))
			return (cpy);
		cpy++;
	}
	return (NULL);
}
