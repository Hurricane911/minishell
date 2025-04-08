/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:38:34 by joyim             #+#    #+#             */
/*   Updated: 2025/04/08 23:05:28 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

s_token *create_token(char *value, int type);
void append_token(s_token **head, s_token *new_node);

s_token *create_token(char *value, int type)
{
	s_token *new_node;
	
	new_node = malloc(sizeof(s_token));
	if (!new_node)
		return (NULL);
	new_node->value;
	new_node->type;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void append_token(s_token **head, s_token *new_node)
{
	s_token *temp;
	temp = *head;
	if(!*head)
	{
		*head = new_node;
		return ;
	}
	temp->next = new_node;
	new_node->prev = temp;

	ft_printf("Token value: %s, Token type: %d\n", temp->value, temp->type);
}