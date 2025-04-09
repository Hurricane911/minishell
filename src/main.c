/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:16 by joyim             #+#    #+#             */
/*   Updated: 2025/04/09 20:22:50 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main()
{
	// if(ac < 2)
	// 	return(1);
	// else
	// 	tokenization(av[1]);
	
    t_data data = {0};

	tokenization("ls -la /home | grep file", &data);
	// [WORD:"ls"] -> [WORD:"-la"] -> [WORD:"/home"] -> [PIPE:"|"] -> [WORD:"grep"] -> [WORD:"file"]
	
}