# include "lemin.h"
# include <limits.h>


void	check_startend(char *line, t_data *data)
{
	if (check_line(line) == 2 && !CHECK_BIT(data->status, START))
		data->status |= START;
	else if (check_room(line) == 1 && CHECK_BIT(data->status, START))
	{
		data->status ^= START;
		data->start = ft_strdup(line);
	}
	else if (check_line(line) == 3 && !CHECK_BIT(data->status, END))
		data->status |= END;
	else if (check_room(line) == 1 && CHECK_BIT(data->status, END))
	{
		data->end = ft_strdup(line);
		data->status ^= END;
	}
	if (check_room(line) == 1)
		get_rooms(line, data);
	else if (next_step(line, data) == 1)
		data->status |= ROOMS;
}