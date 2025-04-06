/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:43:05 by joyim             #+#    #+#             */
/*   Updated: 2025/02/06 19:19:25 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
		len++;
	}
	return (len);
}
/*
int main()
{
	char *s = "what";
	ft_putstr(s) ;
	return 0;
}
*/