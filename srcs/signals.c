/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:36:20 by joyim             #+#    #+#             */
/*   Updated: 2025/07/19 17:41:39 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
SIGINT	(ctrl + c)
SIGQUIT	(ctrl + \)
EOF		(ctrl + d)
 */
void set_signal_input(void);
void ignore_sigquit(void);
static void handle_sigint(int signum);

void set_signal_input(void)
{
	struct sigaction act;

	ignore_sigquit();
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = &handle_sigint;
	sigaction(SIGINT, &act, NULL);
}

void ignore_sigquit(void)
{
	struct sigaction act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &act, NULL);
}

static void handle_sigint(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void set_signals_executions(void)
{
	struct sigaction act;
	
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = handle_execution_signals;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

void	handle_execution_signals(int signum)
{
	if (signum == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
	else if(signum == SIGINT)
		ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
}