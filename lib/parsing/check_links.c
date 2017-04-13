# include "lemin.h"
# include <limits.h>

int		check_links(char *line, t_lst *lst)
{
	char **link;

	link = ft_strsplit(line, '-');
// check len str de link max 2 str 
	if (check_exist(link[0], lst) == 0 && (check_exist(link[1], lst) == 0))
	{
		ft_putstr(link[0]);
		ft_putstr("\n");
		// ft_printf("-->[%s]<--\n", link[0]);
		return(1);
	}
	else
	{
		ft_putstr("ERROR");
		return (0);
	}
}
