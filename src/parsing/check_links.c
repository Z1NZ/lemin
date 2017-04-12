# include "lemin.h"
# include <limits.h>

void	check_links(char *line, t_lst *lst)
{
	char **link;

	link = ft_strsplit(line, '-');

	if (check_exist(link[0], lst) == 0)
	{
		ft_printf("-->[%s]<--\n", link[0]);
	}
	else
		ft_printf("ERROR");
	if (check_exist(link[1], lst) == 0)
		ft_printf("-->[%s]<--\n", link[1]);
	else
		ft_printf("ERROR");
}
