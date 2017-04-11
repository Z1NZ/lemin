/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 22:31:25 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:52:37 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freestr(char **s1, char **s2, int nb)
{
	if (nb == 1)
		ft_strdel(s1);
	else if (nb == 2)
		ft_strdel(s2);
	else if (nb == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
}

char	*ft_strjoin_free(char **s1, char **s2, int nb)
{
	int		size;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(*s1) + ft_strlen(*s2) + 1;
	str = (char*)malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	while ((*s1)[i] != '\0')
	{
		str[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		str[i++] = (*s2)[j++];
	str[i] = '\0';
	freestr(s1, s2, nb);
	return (str);
}
