# include "lemin.h"

static void	stock_name(char *line, char **stock)
{
	char *tmp;

	tmp = ft_strchr(line, ' ');
	*tmp = '\0';
	*stock = ft_strdup(line);
	*tmp = ' ';
}

void	check_startend(char *line, t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (check_line(line) == 2 && !CHECK_BIT(data->status, START))
		data->status |= START;
	else if (check_room(line) == 1 && CHECK_BIT(data->status, START))
	{
		data->status ^= START;
		stock_name(line, &data->start);
	}
	else if (check_line(line) == 3 && !CHECK_BIT(data->status, END))
		data->status |= END;
	else if (check_room(line) == 1 && CHECK_BIT(data->status, END))
	{
		data->status ^= END;
		stock_name(line, &data->end);
	}
	if (check_room(line) == 1)
		get_rooms(line, data);
	else if (next_step(line, data) == 1)
		data->status |= ROOMS;
}
