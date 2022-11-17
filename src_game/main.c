/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:25:23 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/11/17 02:25:24 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static void	free_all(t_data *data)
{
	return ;
}

static void	init_data(t_data *data)
{
	data->max_level = MAX_LEVEL;
}

static int	init_date(t_data *data)
{
	data->date = localtime(&data->start_time);
	if (!data->date)
		return (1);
	data->date->tm_year += 1900;
	data->date->tm_mon += 1;
	return (0);
}

static int	init_level(t_data *data)
{
	data->level[0].level = &fn_level1;
	data->level[0].hint = &hint_level1;
	data->level[1].level = &fn_level2;
	data->level[1].hint = &hint_level2;
	data->level[2].level = &fn_level3;
	data->level[2].hint = &hint_level3;
	data->level[3].level = &fn_level4;
	data->level[3].hint = &hint_level4;
	return (0);
}

int	main(void)
{
	t_data	data;

	data = (t_data){};
	init_data(&data);
	if (!time(&data.start_time)
		|| init_date(&data)
		|| init_level(&data)
		|| game(&data)
		|| !time(&data.end_time))
	{
		fprintf(stderr, "Error to load game please retry !\n");
		return (1);
	}
	congratulation(&data);
	free_all(&data);
	return (0);
}
