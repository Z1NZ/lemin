/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoullec <kmoullec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:19:23 by aboudjem          #+#    #+#             */
/*   Updated: 2015/03/12 00:03:42 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cpt_word(char const *s, char c)
{
	int nb_word;

	nb_word = 0;
	while (*s && *s == c)
		++s;
	while (*s)
	{
		while (*s && *s != c)
			++s;
		++nb_word;
		while (*s && *s == c)
			++s;
	}
	return (nb_word);
}

static void		filling(const char *s, char *tab, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] == c)
		++i;
	j = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = 0;
}

static int		cpt_ltt(char **count, char c)
{
	int i;

	i = 0;
	while (**count == c)
		++*count;
	while (**count != c && **count)
	{
		i++;
		++*count;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	*count;
	char	**tab;
	char	*stock;
	int		nb_word;

	if (s == NULL)
		return (NULL);
	nb_word = cpt_word(s, c);
	tab = (char **)malloc(sizeof(*tab) * (nb_word + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb_word] = NULL;
	count = (char *)s;
	i = -1;
	while (++i < nb_word)
	{
		stock = count;
		if ((tab[i] = (char *)malloc(cpt_ltt(&count, c) + 1)) == NULL)
			return (NULL);
		filling(stock, tab[i], c);
	}
	return (tab);
}
