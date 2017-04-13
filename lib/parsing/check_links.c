# include "lemin.h"
# include <limits.h>

int		check_links(char *line, t_lst *lst)
{
	char **link;

	if (count_char(line,'-') != 1 || !(link = ft_strsplit(line, '-')))
		exit(-1);
	// check len str de link max 2 str 
	if (check_exist(link[0], lst) && (check_exist(link[1], lst)))
	{
		ft_putstr(link[0]);
		ft_putstr("\n");
		// add_links(lst, link);
		return(1);
	}
	else
	{
		ft_putstr("ERROR");
		return (0);
	}
}
