/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:25:05 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/11/17 02:25:06 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# define NAME "miniescape"
# define MAX_LEVEL 3

# define COLOR_ESC_TER		   "\033"
# define COLOR_WHITE_TER	   COLOR_ESC_TER"[97m"
# define COLOR_CYAN_TER		   COLOR_ESC_TER"[96m"
# define COLOR_GREEN_TER	   COLOR_ESC_TER"[32m"
# define COLOR_BLUE_TER		   COLOR_ESC_TER"[34m"
# define COLOR_YELLOW_TER	   COLOR_ESC_TER"[33m"
# define COLOR_MAGENTA_TER 	   COLOR_ESC_TER"[35m"
# define COLOR_BOLD_TER		   COLOR_ESC_TER"[1m"
# define COLOR_RESET_TER	   COLOR_ESC_TER"[0m"
# define COLOR_RESET_BOLD_TER  COLOR_ESC_TER"[21m"


# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <fcntl.h>
# include <termios.h>
# include "miniescape.h"


#endif
