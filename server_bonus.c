/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:15:09 by oronda            #+#    #+#             */
/*   Updated: 2021/11/06 12:15:09 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	handle_eot_request(unsigned int *pid)
{
	kill(*pid, SIGUSR2);
	*pid = 0;
}

void	handle_sigs(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static unsigned int		client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return (handle_eot_request(&client_pid));
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("|*****************|\n", 1);
	ft_putstr_fd("| Server Launched |\n", 1);
	ft_putstr_fd("|                 |\n", 1);
	ft_putstr_fd("*******************\n", 1);
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nListening ...\n", 1);
	sa.sa_sigaction = handle_sigs;
	sa.sa_flags = SA_SIGINFO ;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
