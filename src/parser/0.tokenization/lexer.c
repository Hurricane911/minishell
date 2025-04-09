/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:55:28 by joyim             #+#    #+#             */
/*   Updated: 2025/04/09 20:07:40 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int tokenization (char *input, t_data *data);
int save_word_or_seperator(int *i_current, char *input, int from, t_token **token);
static void save_word(char *input, int i_current, int from, t_token **token);
static void save_seperator(char *input, int i_current, int type, t_token **token);

int tokenization (char *input, t_data *data)
{
	int i_current;
	int end;
	int from;
	int is_quote;

	i_current = -1;
	from = 0;
	end = ft_strlen(input);
	is_quote = NO_QUOTE;
	while(++i_current <= end)
	{
		is_quote = check_quote(is_quote, input, i_current);
		// ft_printf("%d\n", is_quote);
		if(is_quote == NO_QUOTE) //0
			from = save_word_or_seperator(&i_current, input, from, &data->tokens);
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

int save_word_or_seperator(int *i_current, char *input, int from, t_token **token)
{
	int type;
	type = get_seperator(input, *i_current);
	// ft_printf("%d", type);
	if(type)
	{
		// ft_printf("%s", "hel2\n");
		if((*i_current) != 0 && !get_seperator(input, *i_current - 1))
			// ft_printf("%s", "hel");
			save_word(input, *i_current, from, token);
		
		if((type > WORD) || type == END_OF_FILE)
		{
			// ft_printf("%d", REDIRECT_OUT);
			save_seperator(input, *i_current, type, token);
			if(type == APPEND || type == HEREDOC)
				(*i_current)++;
		}
		from = (*i_current) + 1;
	}
	return (from);
}

static void save_word(char *input, int i_current, int from, t_token **token)
{
	int i;
	char *word;

	i = 0;
	word = malloc(sizeof(char) * (i_current - from + 1));
	if(!word)
		return print_error(MALLOC_ERROR);
	while(from < i_current)
		word[i++] = input[from++];
	word[i] = '\0';
	// ft_printf("%s\n", word);
	append_token(token, create_token(word, WORD));
	// ft_printf("end");
}

static void save_seperator(char *input, int i_current, int type, t_token **token)
{
	int i;
	char *sep;
	int sep_len;

	// ft_printf("%d", type);
	i = 0;
	if (type == APPEND || type == HEREDOC )
		sep_len = 2;
	else
	{
		sep_len = 1;
		// ft_printf("%d\n", sep_len);
	}
	sep = malloc(sizeof(char) * (sep_len + 1));
	if(!sep)
		return print_error(MALLOC_ERROR);
	while(i < sep_len)
		sep[i++] = input[i_current++];
	sep[i] = '\0';
	// ft_printf("%s\n", sep);
	append_token(token, create_token(sep, type));

}