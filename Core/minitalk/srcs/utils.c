/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:33:14 by ele-sage          #+#    #+#             */
/*   Updated: 2023/06/15 09:42:49 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error_server(t_server *server)
{
	ft_printf("\n%sserver: unexpected error.%s\n", RED, END);
	if (server->str != NULL)
		free(server->str);
	exit(EXIT_FAILURE);
}

void	print_string(t_server *server)
{
	ft_printf("\n\n%sMessage receive: %s", YELLOW, END);
	ft_printf("%s%s\n", server->str, END);
	ft_printf("%s%d signals recieved from client PID: %d%s\n",
		GREEN, server->bit + 1, server->client_pid, END);
	ft_printf("%s\nWaiting for client...%s\n", FAINT, END);
	if (kill(server->client_pid, SIGUSR1) == -1)
		signal_error_server(server);
	reset_server(server);
}

void	reset_server(t_server *server)
{
	if (server->str != NULL)
		free(server->str);
	server->client_pid = 0;
	server->current_byte = 0;
	server->strlen = 0;
	server->bit = 0;
	server->byte = 0;
	server->str = NULL;
}

void	signal_error_client(void)
{
	ft_printf("\n%sclient: unexpected error.%s\n", RED, END);
	exit(EXIT_FAILURE);
}
