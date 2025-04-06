/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:01:09 by joyim             #+#    #+#             */
/*   Updated: 2025/02/06 19:18:07 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main()
{
	char testChar;

	printf("enter a char:");
	scanf("%c", &testChar);

	if(ft_isascii(testChar))
	{
		printf("%c is an ASCII char", testChar);
	}
	else
		printf("%c is not an ASCII char", testChar);

return (0);
}
*/
