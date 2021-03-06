#include "lemin.h"

int		check_links(char *line, t_lst *lst, t_data *data)
{
	char **link;

	link = ft_strsplit(line, '-');
	if (count_char(line, '-') != 1 || !link || tab_len(link) != 2)
	{
		ft_free_tab(link);
		ft_exit(data);
	}
	if (add_links(check_exist(link[0], lst), check_exist(link[1], lst), data))
	{
		ft_free_tab(link);
		return (1);
	}
	ft_free_tab(link);
	ft_putstr("Error Links");
	return (0);
}
