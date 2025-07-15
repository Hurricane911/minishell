/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:42:15 by joyim             #+#    #+#             */
/*   Updated: 2025/07/15 14:14:07 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	int i;
	(void) ac;
	(void) av;
	i = 0;

	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			printf("current path %s", envp[i] + 5);
			return (0);
		}
		i++;
		
	}
	printf("not foun");
	return (1);
	// char *input;
	// while(1)
	// {
	// 	if (parse_input(&data, input) == SUCCESS)
	// 	ft_printf("success");
	// }
	
}