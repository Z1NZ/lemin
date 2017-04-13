/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 01:14:02 by aboudjem          #+#    #+#             */
/*   Updated: 2016/10/30 01:20:21 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)big);
	while (big[i])
	{
		while (little[pos] == big[i + pos])
		{
			if (pos == len - 1)
				return ((char *)big + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
