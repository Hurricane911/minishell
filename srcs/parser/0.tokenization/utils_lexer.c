/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:38:05 by joyim             #+#    #+#             */
/*   Updated: 2025/07/22 10:39:25 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int			check_quote(int is_quote, char *input, int i_current);
int	get_seperator(char *input, int i_current);


int check_quote(int get_quote, char *input, int i_current)
{
	if(input[i_current] == '\'' && get_quote == COMPLETE)
		return (get_quote = SINGLE_QUOTE);
	else if(input[i_current] == '\'' && get_quote == SINGLE_QUOTE)
		return (get_quote = COMPLETE);
	else if(input[i_current] == '\"' && get_quote == COMPLETE)
		return (get_quote = DOUBLE_QUOTE);
	else if(input[i_current] == '\"' && get_quote == DOUBLE_QUOTE)
		return (get_quote = COMPLETE);
	
	return (get_quote);
}

int	get_seperator(char *input, int i_current)
{
	if (ft_isspace(input[i_current]))
		return (SPACES);
	else if (input[i_current] == '|')
		return (PIPE);
	else if (input[i_current] == '<' && input[i_current + 1] == '<')
		return (HEREDOC);
	else if (input[i_current] == '<')
		return (REDIRECT_IN);
	else if (input[i_current] == '>' && input[i_current + 1] == '>')
		return (APPEND);
	else if (input[i_current] == '>')
		return (REDIRECT_OUT);
	else if (input[i_current] == '\0')
		return (END_OF_FILE);
	else
		return (NONE);
}