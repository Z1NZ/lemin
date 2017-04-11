#include "lemin.h"

size_t		len_str(char *s)
{
	size_t i;

	i = 0;
	if (s[0] == '#' || s[0] == 'L')
		return(ft_error(5));
	while(s[i] != ' ' && s[i] != '\0')
		i++;
	return(i);
}

int		count_char(char *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
		return(count);
}


int		check_nb(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == ' ' || ft_isdigit(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	init_all(char **line, t_rooms *r, t_lst *lst)
{
	*line = NULL;
	lst = NULL;
	r->i = 0;
	r->y = 0;
	r->x = 0;
	r->room = NULL;
	r->start = NULL;
	r->end = NULL;
	r->index = 0;
}