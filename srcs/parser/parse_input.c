/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:48:28 by joyim             #+#    #+#             */
/*   Updated: 2025/07/23 14:48:20 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int tokenization(t_data *data, char *input);
int parse_input(t_data *data, char *input);
int ft_exit(t_data *data, char **args);
void exit_process(int exit_status);

int ft_exit(t_data *data, char **args)
{
	// int argc;
	int exit_code;

	(void) args;
	// argc = 0;
	// if(args == NULL)
	// 	argc = 0;
	ft_putendl_fd("exit", 1);
	
	exit_code = data->last_exit_code;
	exit_process(exit_code);

	return (0);
}

void exit_process(int exit_status)
{
	exit(exit_status);	
}

int parse_input(t_data *data, char *input)
{
	if(input == NULL)
		ft_exit(data, NULL);
	if(tokenization(data, input) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}
