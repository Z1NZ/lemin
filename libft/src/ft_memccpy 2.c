/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:06:41 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/29 22:57:58 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*s1++ = *s2++) == d)
			return (s1);
		i++;
	}
	return (NULL);
}
