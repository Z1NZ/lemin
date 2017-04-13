# include "lemin.h"
# include <limits.h>

int		check_links(char *line, t_lst *lst)
{
	char **link;

	if (count_char(line,'-') != 1 || !(link = ft_strsplit(line, '-')))
		exit(-1);// check len str de link max 2 str 
	if (add_links(check_exist(link[0], lst), check_exist(link[1], lst)))
		{
			// printf("\n==[%s]==\n", line);
		return(1);// free(link) a ne pas oublier
	}
	ft_putstr("ca a pa link");
	return (0);
}
