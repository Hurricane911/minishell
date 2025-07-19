/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:56:02 by joyim             #+#    #+#             */
/*   Updated: 2025/07/19 17:31:02 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
// #include "stdio.h"
# include <signal.h>
# include <readline/readline.h>



enum e_error_codes
{
	SUCCESS,
};

typedef struct s_envp
{
	char *variable_name;
	char *value;
	struct s_envp *prev;
	struct s_envp *next;
}t_envp;

typedef struct s_data
{
	t_envp *our_envp;
	char **envp_array;
	int last_exit_code;
}t_data;

// init.c
void init_shell_data(t_data *data, char **envp);
void init_envp(t_data *data, char **envp);
void print_list(t_envp *head);


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

// signals.c
void set_signal_input(void);
void ignore_sigquit(void);
void set_signals_executions(void);
void	handle_execution_signals(int signum);



#endif
