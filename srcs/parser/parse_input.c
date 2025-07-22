/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:48:28 by joyim             #+#    #+#             */
/*   Updated: 2025/07/22 23:18:52 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	save_word_or_seperator(int *i_current, char *input, int from, t_data *data);
int			get_seperator(char *input, int i_current);
int tokenization(t_data *data, char *input);
static void	save_word(int from, char *input, int i_current, t_token **tokens);
int	ft_isspace(int c);
t_token *create_node(char *word, int type);
void append_node(t_token **head, t_token *new_node);
int parse_input(t_data *data, char *input);
static void save_seperator(int i_current, int type, char *input, t_token **tokens);


int parse_input(t_data *data, char *input)
{
	
	if(tokenization(data, input) == FAILURE)
		return (FAILURE);

	return (SUCCESS);
}

int tokenization(t_data *data, char *input)
{
	int from;
	int end;
	int i_current;
	int get_quote;

	get_quote = COMPLETE;
	i_current = -1;

	end  = ft_strlen(input);
	from = 0;

	while(++i_current <= end)
	{
		get_quote = check_quote(get_quote, input, i_current);
		if(get_quote == COMPLETE)
			from = save_word_or_seperator(&i_current, input, from, data);
	}
	if (get_quote != COMPLETE)
	{
		if(get_quote == SINGLE_QUOTE)
			print_error(UNCLOSED_SINGLE_QUOTE);
		else if(get_quote == DOUBLE_QUOTE)
			print_error(UNCLOSED_DOUBLE_QUOTE);
		return (FAILURE);
	}
	return (SUCCESS);
}

int save_word_or_seperator(int *i_current, char *input, int from, t_data *data)
{
	int type;

	type = get_seperator(input, (*i_current));
	if(type)
	{
		if((*i_current) != 0 && !get_seperator(input, (*i_current) - 1))
			save_word(from, input, (*i_current), &data->tokens);
		if(type > WORD || type == END_OF_FILE)
		{
			save_seperator((*i_current), type, input, &data->tokens);
			if(type == APPEND || type == HEREDOC)
				(*i_current)++;
		}
		from = (*i_current) + 1;
	}
	return (from);
}


static void	save_word(int from, char *input, int i_current, t_token **tokens)
{
	char *word;
	int i;
	i = 0;
	word = malloc(sizeof(char) * (i_current - from) + 1);
	while(from < i_current)
		word[i++] = input[from++];
	word[i] = '\0';
	append_node(tokens, create_node(word, WORD));
}

static void save_seperator(int i_current, int type, char *input, t_token **tokens)
{
	char *sep;
	int i;
	int sep_length;

	i = 0;
	if(type == APPEND || type == HEREDOC)
		sep_length = 2;
	else
		sep_length = 1;
	sep = malloc(sizeof(char) * (sep_length + 1));
	if(!sep)
		print_error(MALLOC_ERROR);
	while(i < sep_length)
		sep[i++] = input[i_current++];
	sep[i] = '\0';
	append_node(tokens, create_node(sep, type));
}