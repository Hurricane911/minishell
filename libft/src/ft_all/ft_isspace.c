/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:17:57 by joyim             #+#    #+#             */
/*   Updated: 2025/04/08 12:25:40 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int ft_isspace(int c)
{
	if(c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}