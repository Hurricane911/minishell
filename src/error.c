/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:14:09 by joyim             #+#    #+#             */
/*   Updated: 2025/04/08 13:13:35 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_error(int error_code);

void print_error(int error_code)
{
	if(error_code == FAILURE)
		ft_putendl_fd(MSG_FAILURE, 2);
	else if(error_code == UNCLOSED_SINGLE_QUOTE)
		ft_putendl_fd(MSG_UNCLOSED_SINGLE_QUOTE, 2);
	else if(error_code == UNCLOSED_DOUBLE_QUOTE)
		ft_putendl_fd(MSG_UNCLOSED_DOUBLE_QUOTE, 2);
	else if(error_code == MALLOC_ERROR)
		ft_putendl_fd(MSG_MALLOC_ERROR, 2);
	else
		ft_putendl_fd("unknown error", 2);
}