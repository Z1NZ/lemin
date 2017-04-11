/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 01:44:01 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/30 01:44:37 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (ft_strdup(s));
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || (s[i] == '\n' && s[i]))
		i++;
	while (s[j] == ' ' || s[j] == '\t' || (s[j] == '\n' && j > 0))
		j--;
	if (i == ft_strlen(s))
		return (ft_strnew(0));
	str = ft_strnew(j - i + 1);
	if (str)
	{
		str = ft_strsub(s, i, j - i + 1);
		return (str);
	}
	return (NULL);
}
