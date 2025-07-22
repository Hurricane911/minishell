/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:56:02 by joyim             #+#    #+#             */
/*   Updated: 2025/07/22 23:15:51 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
// #include "stdio.h"
# include <signal.h>
# include <readline/readline.h>

# define MSG_UNCLOSED_SINGLE_QUOTE "minishell: unexpected \
EOF while looking for matching '"
# define MSG_UNCLOSED_DOUBLE_QUOTE "minishell: unexpected \
EOF while looking for matching \""
# define MSG_MALLOC_ERROR "malloc error"


enum e_token_type
{
	END_OF_FILE = -1,
	NONE,
	SPACES,
	WORD,
	VARIABLE,
	PIPE,
	REDIRECT_IN,
	HEREDOC,
	REDIRECT_OUT,
	APPEND,
};

enum e_error_codes
{
	SUCCESS,
	FAILURE,
	SYNTAX_ERROR,
	UNCLOSED_SINGLE_QUOTE,
	UNCLOSED_DOUBLE_QUOTE,
	QUOTE_ERROR,
	MALLOC_ERROR,
	CMD_NOT_EXECUTABLE = 126,
	CMD_NOT_FOUND = 127,
};

enum e_quote_status
{
	COMPLETE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
};

typedef struct s_envp
{
	char *variable_name;
	char *value;
	struct s_envp *prev;
	struct s_envp *next;
}t_envp;

typedef struct s_token
{
	char *value;
	char type;
	struct s_token *next;
	struct s_token *prev;
}t_token;

typedef struct s_data
{
	t_envp *our_envp;
	char **envp_array;
	int last_exit_code;
	t_token *tokens;
}t_data;


// init.c
void init_shell_data(t_data *data, char **envp);
void init_envp(t_data *data, char **envp);
void print_list(t_envp *head);

// mkdir utils

// envp_nodes.c
void append_envp(t_envp **head, t_envp *new_node);
t_envp *create_envp_node(char *var_name, char *value);

// ft_freee_2d_array.c
void ft_free_2d_array(char **array);
void free_envp_list(t_envp *head);
void free_ptr(void **ptr);

// convert_envp.c
char **convert_envp(t_data *data, t_envp *envp);
int count_nodes(t_envp *head);

// error.c
void print_error(int error_code);

// ft_isspace.c
int	ft_isspace(int c);

// utils_t_tokens.c
t_token *create_node(char *word, int type);
void append_node(t_token **head, t_token *new_node);

// signals.c
void set_signal_input(void);
void ignore_sigquit(void);
void set_signals_executions(void);
void	handle_execution_signals(int signum);

// pars_input.c
int parse_input(t_data *data, char *input);

// lexer.c

// lexer_utils.c
int			check_quote(int is_quote, char *input, int i_current);
int	get_seperator(char *input, int i_current);


#endif
