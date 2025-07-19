/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:48:27 by joyim             #+#    #+#             */
/*   Updated: 2025/07/18 21:25:11 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_free_2d_array(char **array);
void free_envp_list(t_envp *head);
void free_ptr(void **ptr);


void ft_free_2d_array(char **array)
{
	size_t i;

	i = 0;
	
	while(array[i])
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
	while(current)
	{
		next = current->next;
		free(current->variable_name);
		free(current->value);
		free(current);
		current = next;
	}
}

void free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}