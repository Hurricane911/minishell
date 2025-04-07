/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:55:28 by joyim             #+#    #+#             */
/*   Updated: 2025/04/07 14:22:38 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int tokenization (char *input);

int tokenization (char *input)
{
	int i_current;
	int end;
	// int from;
	int is_quote;

	i_current = -1;
	// from = 0;
	end = ft_strlen(input);
	is_quote = NO_QUOTE;
	while(++i_current <= end)
	{
		is_quote = check_quote(is_quote, input, i_current);
		if(is_quote == NO_QUOTE)
			
	}
	if(is_quote != NO_QUOTE)
	{
		if(is_quote == SINGLE_QUOTE)
			print_error(UNCLOSED_SINGLE_QUOTE);
			// ft_printf("%s", "single_quote");
		else if(is_quote == DOUBLE_QUOTE)
			print_error(UNCLOSED_DOUBLE_QUOTE);
			// ft_printf("%s", "double_quote");
		return(FAILURE);
	}
	return (SUCCESS);
}