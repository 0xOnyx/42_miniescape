/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniescape.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:22:18 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/11/17 02:25:00 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIESCAPE_H
# define MINIESCAPE_H

typedef struct s_data	t_data;

typedef struct s_user {
	char	*mail;
	char	*username;
	int		subscribe;
}	t_user;

typedef struct s_time
{
	unsigned long		min;
	unsigned long		sec;
}	t_time;

typedef struct s_level
{
	int (*level)(t_data *);
	int	(*hint)(t_data *);
}	t_level;

struct s_data {
	struct tm	*date;
	int			current_level;
	int			max_level;
	time_t		start_time;
	time_t		end_time;
	t_time		time_play;
	int			score;
	t_user		user;
	t_level		level[4];
};

int		game(t_data *data);
void	congratulation(t_data *data);

int		fn_level1(t_data *data);
int		fn_level2(t_data *data);
int		fn_level3(t_data *data);
int 	fn_level4(t_data *data);

int		hint_level1(t_data *data);
int		hint_level2(t_data *data);
int		hint_level3(t_data *data);
int 	hint_level4(t_data *data);

#endif
