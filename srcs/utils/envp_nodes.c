/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:18:04 by joyim             #+#    #+#             */
/*   Updated: 2025/07/18 13:58:57 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp *create_envp_node(char *var_name, char *value);
void append_envp(t_envp **head, t_envp *new_node);

t_envp *create_envp_node(char *var_name, char *value){

	t_envp *new_node;

	new_node = (t_envp *)malloc(sizeof(t_envp));
	if(!new_node)
		return NULL;

	new_node->variable_name = ft_strdup(var_name);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

void	append_envp(t_envp **head, t_envp *new_node)
{
	t_envp	*temp;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

