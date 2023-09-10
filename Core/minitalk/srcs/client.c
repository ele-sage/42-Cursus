/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:20 by ele-sage          #+#    #+#             */
/*   Updated: 2023/06/13 14:49:35 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

static void	char_to_bin(unsigned char c, int pid, int bit)
{
	if ((c >> bit) & 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			signal_error_client();
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			signal_error_client();
	}
}

static void	int_to_bin(int nb, int pid, int bit)
{
	if ((nb >> bit) & 1)
	{
		if (kill(pid, SIGUSR2) == -1)
			signal_error_client();
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			signal_error_client();
	}
}

static void	action_send(int sig, siginfo_t *info, void *context)
{
	static int				len = 30;
	static unsigned long	bit = 0;
	static int				s_pid = 0;

	(void)context;
	if (s_pid == 0)
		s_pid = info->si_pid;
	if (sig == SIGUSR1)
	{
		ft_printf("\n\n%s%d signals sent and received to server PID: %d%s\n",
			GREEN, bit + 32, s_pid, END);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR2 && len >= 0)
		int_to_bin(ft_strlen(g_str), s_pid, len--);
	else if (sig == SIGUSR2 && bit <= ft_strlen(g_str) * 8)
	{
		char_to_bin(g_str[bit / 8], s_pid, 7 - bit % 8);
		bit++;
	}
	else
		signal_error_client();
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	act.sa_sigaction = action_send;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (ac == 3)
	{
		g_str = av[2];
		ft_printf("%sclient pid: %d%s\n", BLUE, getpid(), END);
		ft_printf("%sText currently sending.. %s\n", YELLOW, END);
		if (sigaction(SIGUSR1, &act, NULL) == -1)
			signal_error_client();
		if (sigaction(SIGUSR2, &act, NULL) == -1)
			signal_error_client();
		int_to_bin(ft_strlen(av[2]), ft_atoi(av[1]), 31);
		while (1)
			pause();
	}
	else
		ft_printf("%s%s%s\n", BLUE, USAGE, END);
	return (EXIT_SUCCESS);
}
