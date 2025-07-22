// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utils_t_tokens.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/07/22 10:40:52 by joyim             #+#    #+#             */
// /*   Updated: 2025/07/22 15:21:30 by joyim            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

t_token *create_node(char *word, int type);
void	append_node(t_token **head, t_token *new_node);
// void print_head(t_token **head);

void append_node(t_token **head, t_token *new_node)
{
	t_token *temp;
	
	temp = *head;
	if (!new_node)
		return ;

	if(!*head)
	{
		*head = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	// print_head(head);
}


// void print_head(t_token **head)
// {
//     t_token *current = *head;  // Dereference to get actual token
    
//     printf("Tokens: ");
//     while(current)
//     {
//         printf("[%s] ", current->value);  // Fixed: use printf and current->value
//         current = current->next;          // Fixed: use current
//     }
//     printf("\n");
// }

t_token *create_node(char *word, int type)
{
	t_token *new_node;

	new_node = malloc(sizeof(t_token));
	if(!new_node)
		return (NULL);
	new_node->value = word;
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = NULL;

	// printf("%s\n", new_node->value);
	return (new_node);
}