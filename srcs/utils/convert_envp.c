/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:19:22 by joyim             #+#    #+#             */
/*   Updated: 2025/07/19 13:10:43 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char **convert_envp(t_data *data, t_envp *envp);
int count_nodes(t_envp *head);
char **join_env_var(char **envp_array, t_envp *envp);

int count_nodes(t_envp *head)
{
	int count;

	count = 0;
	while(head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

char **convert_envp(t_data *data, t_envp *envp)
{
	int i;
	char **envp_array;

	if(data->envp_array)
		ft_free_2d_array(data->envp_array);
	
	i = count_nodes(envp);
	envp_array = (char **)malloc((i + 1) * sizeof(char *));
	if(!envp_array)
		return (NULL);
	envp_array = join_env_var(envp_array, envp);
	return (envp_array);
}

char **join_env_var(char **envp_array, t_envp *envp)
{
	t_envp	*temp;
	char	*var_name;
	int		i;

	i = 0;
	temp = envp;

	while(temp)
	{
		var_name = ft_strjoin(temp->variable_name, "=");
		envp_array[i] = ft_strjoin(var_name, temp->value);
		free_ptr((void **)&var_name);
		if(!envp_array[i])
		{
			ft_free_2d_array(envp_array);
			return (NULL);
		}
		temp = temp->next;
		i++;
	}
	envp_array[i] = NULL; 
	return (envp_array);	
}