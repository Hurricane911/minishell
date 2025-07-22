/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:42:15 by joyim             #+#    #+#             */
/*   Updated: 2025/07/22 11:18:14 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell_data(t_data *data, char **envp);
void	init_envp(t_data *data, char **envp);
void append_envp(t_envp **head, t_envp *new_node);
t_envp *create_envp_node(char *var_name, char *value);
void ft_free_2d_array(char **array);
void free_envp_list(t_envp *head);

int	main(int ac, char **av, char **envp)
{
	t_data data;
	char *input;
	// int i;
	(void) ac;
	(void) av;
	// i = 0;

	init_shell_data(&data, envp);
	free_envp_list(data.our_envp);
	ft_free_2d_array(data.envp_array);

	while(1)
	{
		set_signal_input();

		input = readline("minishell$ > ");
		set_signals_executions();

		// (void)input;
		if(parse_input(&data, input) == SUCCESS)
		{
			printf("nice");
		}

	}

	return (0);
}
