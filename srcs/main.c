/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:42:15 by joyim             #+#    #+#             */
/*   Updated: 2025/07/18 11:00:03 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_shell_data(t_data *data, char **envp);
void init_envp(t_data *data, char **envp);
void append_envp(t_envp **head, t_envp *new_node);
t_envp *create_envp_node(char *var_name, char *value);
void ft_free_2d_array(char **array);
void free_envp_list(t_envp *head);
void print_list(t_envp *head);


int main(int ac, char **av, char **envp)
{
	t_data data;
	// int i;
	(void) ac;
	(void) av;
	// i = 0;

	init_shell_data(&data, envp);

	// char *input;
	// while(1)
	// {
	// 	if (parse_input(&data, input) == SUCCESS)
	// 	ft_printf("success");
	// }
	
	// Clean up memory before exit
	free_envp_list(data.our_envp);
	
	return (0);
}

void init_shell_data(t_data *data, char **envp)
{
	data->our_envp = NULL;
	init_envp(data, envp);
}

void print_list(t_envp *head)
{
	while(head)
	{
		printf("word: %s\n", head->variable_name);
		head = head->next;
	}
}

void init_envp(t_data *data, char **envp)
{
	char **key_value;
	int i;

	i = 0;
	while(envp[i])
	{
		key_value = ft_split(envp[i], '=');
		if (key_value)
		{
			append_envp(&data->our_envp, create_envp_node(key_value[0], key_value[1]));
			ft_free_2d_array(key_value);  // Free the allocated memory
		}
		i++;
	}
	print_list(data->our_envp);
}

t_envp *create_envp_node(char *variable, char *value)
{
	t_envp *new_node;

	if(!variable)
		return NULL;
	new_node = (t_envp *)malloc(sizeof(t_envp));
	if(!new_node)
		return NULL;
	new_node->variable_name = ft_strdup(variable);
	new_node->value = ft_strdup(value ? value : "");  // Handle NULL value
	
	// Check if strdup failed
	if (!new_node->variable_name || !new_node->value)
	{
		free(new_node->variable_name);
		free(new_node->value);
		free(new_node);
		return NULL;
	}
	
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void append_envp(t_envp **head, t_envp *new_node)
{
	t_envp *current;

	if (!new_node)  // Check if node creation failed
		return;
		
	if(!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	
	while(current->next)
		current = current->next;
	
	current->next = new_node;
	new_node->prev = current;

	// printf("%s: %s\n", current->variable_name, current->value);
}

void ft_free_2d_array(char **array)
{
	int i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void free_envp_list(t_envp *head)
{
	t_envp *current;
	t_envp *next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->variable_name);
		free(current->value);
		free(current);
		current = next;
	}
}