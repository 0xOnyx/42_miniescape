#include "includes.h"

void	make_time(t_data *data, unsigned long diff)
{
	data->time_play.sec = diff % 60;
	data->time_play.min = diff / 60;
}

void	congratulation(t_data *data)
{
	unsigned long		diff;

	diff = (unsigned long)difftime(data->start_time, data->end_time);
	make_time(data, diff);
	data->score = (data->current_level * 100) / data->max_level;
	fprintf(stdout, \
	"/* ************************************************************************** */\n" \
	"/*                                                                            */\n" \
	"/*                                                        :::      ::::::::   */\n" \
	"/*   BRAVO !     VOICI TON SCORE =>   %3d %%             :+:      :+:    :+:   */\n" \
	"/*                                                    +:+ +:+         +:+     */\n" \
	"/*   TIME:  %02lum%02lus                                  +#+  +:+       +#+        */\n" \
	"/*                                                +#+#+#+#+#+   +#+           */\n" \
	"/*                                                     #+#    #+#             */\n" \
	"/*   Created: %4d/%2d/%2d %2d:%2d:%d                     ###   ########.ch       */\n" \
	"/*                                                                            */\n" \
	"/* ************************************************************************** */\n",
		data->score, data->time_play.min, data->time_play.sec,
		data->date->tm_year, data->date->tm_mon, data->date->tm_mday,
		data->date->tm_hour, data->date->tm_min, data->date->tm_min);
}


