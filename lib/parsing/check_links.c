# include "lemin.h"
# include <limits.h>

int		check_links(char *line, t_lst *lst)
{
	char **link;

	if (count_char(line,'-') != 1 || !(link = ft_strsplit(line, '-')))
		exit(-1);// check len str de link max 2 str 
	if (!link[0] || !link[1])
		exit(-1);
	if (add_links(check_exist(link[0], lst), check_exist(link[1], lst)))
		return(1);// free(link) a ne pas oublier
	ft_putstr("Error Links");
	return (0);
}
