/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:56:08 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/21 17:24:03 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src1 < dst1)
		while ((int)(--len) >= 0)
			(dst1[len]) = (src1[len]);
	else
		while (i < len)
		{
			dst1[i] = src1[i];
			i++;
		}
	return (dst);
}
