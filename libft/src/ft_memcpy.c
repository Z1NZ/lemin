/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:59:25 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/29 21:50:32 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;
	size_t		i;

	i = 0;
	dst1 = dst;
	src1 = src;
	while (i != n)
	{
		*dst1 = *src1;
		dst1++;
		src1++;
		i++;
	}
	return (dst);
}
