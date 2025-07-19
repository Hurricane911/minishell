/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:51:13 by joyim             #+#    #+#             */
/*   Updated: 2025/07/19 13:12:33 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_shell_data(t_data *data, char **envp);
void init_envp(t_data *data, char **envp);
// void print_list(t_envp *head); //test for envp linklist 
// static void print_array(char **array);

// void print_list(t_envp *head)
// {
// 	while(head)
// 	{
// 		printf("variable: %s, value: %s\n", head->variable_name, head->value);
// 		head = head->next;
// 	}
// }

void init_shell_data(t_data *data, char **envp)
{
	data->our_envp = NULL;
	data->envp_array = NULL;  // Initialize to NULL to prevent garbage values
	init_envp(data, envp);
}

void init_envp(t_data *data, char **envp)
{
	int i;
	char **key_value;
	

	i = 0;
	while(envp[i])
	{
		key_value = ft_split(envp[i], '=');

		append_envp(&data->our_envp, create_envp_node(key_value[0], key_value[1]));
		ft_free_2d_array(key_value);
		i++;
	}
	// print_list(data->our_envp);
	data->envp_array = convert_envp(data, data->our_envp);
	print_array(data->envp_array);
}

// static void print_array(char **array) //test for envp double array
// {
// 	int i = 0;
// 	char **current;
// 	current = array;

// 	while(current[i])
// 	{
// 		ft_printf("array[%d]: %s \n", i, current[i] );
// 		i++;
// 	}

// }