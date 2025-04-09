/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:38:34 by joyim             #+#    #+#             */
/*   Updated: 2025/04/09 19:44:21 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *create_token(char *value, int type);
void append_token(t_token **head, t_token *new_node);

t_token *create_token(char *value, int type)
{
	t_token *new_node;
	
	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = NULL;

	// ft_printf("%s\n", new_node->value);
	return (new_node);
}

void append_token(t_token **head, t_token *new_node)
{
	t_token *temp;
	temp = *head;
	if(!*head)
	{
		*head = new_node;
		ft_printf("Token value: %s/ Token type: %d\n", new_node->value, new_node->type);
		return ;
	}
	while(temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;

	ft_printf("Token value: %s/ Token type: %d\n", new_node->value, new_node->type);
}