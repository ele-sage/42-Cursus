/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:29:12 by ele-sage          #+#    #+#             */
/*   Updated: 2023/06/13 14:27:34 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <signal.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define FAINT "\033[2m"
# define END "\033[0m"

# define USAGE "Usage: ./client [server PID] [message]\n"

typedef unsigned char	t_unchar;

// Server
typedef struct s_server
{
	int				client_pid;
	int				strlen;
	int				current_byte;
	unsigned long	bit;
	t_unchar		byte;
	t_unchar		*str;
}					t_server;

void	signal_error_server(t_server *server);
void	print_string(t_server *server);
void	reset_server(t_server *server);

// Client
void	signal_error_client(void);

#endif
