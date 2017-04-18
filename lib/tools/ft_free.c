# include "lemin.h"

void	ft_free(t_data *data)
{
	ft_free_lst(data->lst);
	free(data->start);
	free(data->end);
	free(data);
}
