#include "includes.h"

int	game(t_data *data)
{
	while (data->current_level < data->max_level)
		data->level[data->current_level++].level(data);
	return (0);
}