/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:20:36 by ele-sage          #+#    #+#             */
/*   Updated: 2023/07/21 15:25:03 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	malloc_str(t_server *server)
{
	server->str = malloc(sizeof(t_unchar) * (server->strlen + 1));
	if (server->str == NULL)
	{
		ft_printf("\n%sMalloc error.%s\n", RED, END);
		exit(EXIT_FAILURE);
	}
	server->str[server->strlen] = '\0';
}

static void	add_char(t_server *server)
{
	server->str[server->current_byte] = server->byte;
	server->byte = 0;
	server->current_byte++;
}

static void	set_string_lenght(t_server *server, int sig)
{
	server->strlen |= (sig == SIGUSR2);
	if (server->bit < 31)
		server->strlen <<= 1;
	else
		malloc_str(server);
	if (kill(server->client_pid, SIGUSR2) == -1)
		signal_error_server(server);
	server->bit++;
	ft_printf("%d", server->strlen);
}

static void	action_receive(int sig, siginfo_t *info, void *context)
{
	static t_server	server;

	(void)context;
	if (info->si_pid == 0)
		signal_error_server(&server);
	if (server.client_pid != info->si_pid)
		reset_server(&server);
	if (server.client_pid == 0)
		server.client_pid = info->si_pid;
	if (server.bit < 32)
		set_string_lenght(&server, sig);
	else if (server.current_byte == server.strlen)
		print_string(&server);
	else
	{
		server.byte |= (sig == SIGUSR2);
		if (server.bit % 8 == 7 && server.bit > 31)
			add_char(&server);
		else
			server.byte <<= 1;
		server.bit++;
		if (kill(server.client_pid, SIGUSR2) == -1)
			signal_error_server(&server);
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("%sServer PID: %d%s\n", BLUE, getpid(), END);
	ft_printf("%sWaiting for client...%s\n", FAINT, END);
	act.sa_sigaction = action_receive;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (EXIT_FAILURE);
}