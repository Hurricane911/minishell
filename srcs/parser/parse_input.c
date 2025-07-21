/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:48:28 by joyim             #+#    #+#             */
/*   Updated: 2025/07/21 14:02:22 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_quote(int is_quote, char *input, int i_current);
int	save_word_or_seperator(int *i_current, char *input, int from, t_data *data);
int			get_seperator(char *input, int i_current);
void tokenization(t_data *data, char *input);
static void	save_word(int from, char *input, int i_current, t_token **tokens);
int	ft_isspace(int c);




void parse_input(t_data *data, char *input)
{
	tokenization(data, input);
}

void tokenization(t_data *data, char *input)
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
		{
			from = save_word_or_seperator(&i_current, input, from, data);
		}
	}
}

int	save_word_or_seperator(int *i_current, char *input, int from, t_data *data)
{
	int type;

	type = get_seperator(input, (*i_current));
	if(type)
	{
		if((*i_current) != 0 && !get_seperator(input, (*i_current) - 1))
			save_word(from, input, (*i_current), &data->tokens);
			
	}
	return from;
}


static void	save_word(int from, char *input, int i_current, t_token **tokens)
{
	char *word;
	int i;
	(void) tokens;
	i = 0;
	word = malloc(sizeof(char) * (i_current - from) + 1);
	while(from < i_current)
	{
		word[i++] = input[from++];
	}
	word[i] = '\0';
	printf("%s\n", word);
}

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

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}