/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:56:02 by joyim             #+#    #+#             */
/*   Updated: 2025/04/08 14:16:31 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

# define MSG_FAILURE "error"
# define MSG_UNCLOSED_SINGLE_QUOTE "minishell: unexpected \
EOF while looking for matching \'"
# define MSG_UNCLOSED_DOUBLE_QUOTE "minishell: unexpected \
EOF while looking for matching \""
# define MSG_MALLOC_ERROR "malloc error"

enum e_token_type
{
	END_OF_FILE = -1,
	NONE, //0
	SPACES,
	WORD,
	PIPE,
	HEREDOC,
	REDIRECT_IN,
	APPEND,
	REDIRECT_OUT, //7
};

enum e_error_codes
{
	SUCCESS,
	FAILURE,
	SYNTAX_ERROR,
	UNCLOSED_SINGLE_QUOTE,
	UNCLOSED_DOUBLE_QUOTE,
	MALLOC_ERROR,
	QUOTE_ERROR,
};

enum e_quote_status
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
};

typedef struct s_data
{
	

}t_data;

// 0.tokenization
// lexer.c
int tokenization (char *input);
int save_word_or_seperator(int *i_current, char *input, int from);

// lexer_utils.c
int check_quote(int is_quote, char *input, int i_current);
int get_seperator(char *input, int i_current);

// error.c
void print_error(int error_code);


#endif
