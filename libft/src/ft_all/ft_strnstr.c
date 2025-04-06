/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:47:08 by joyim             #+#    #+#             */
/*   Updated: 2025/02/06 19:18:07 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(find))
		return ((char *)str);
	i = -1;
	while (++i < len && *(str + i))
	{
		j = -1;
		while ((i + ++j) < len && *(str + i + j) == *(find + j))
			if (!*(find + j + 1))
				return ((char *)(str + i));
	}
	return (NULL);
}
/*
int main()
{
    char *haystack = "Hello world";
    char *needle = "world";
    char *ptr = ft_strnstr(haystack, needle, strlen(haystack));
    if (ptr != NULL) {
        printf("Found at position: %ld\n", ptr - haystack);
        printf("Substring found: %s\n", ptr);
    } else {
        printf("Substring not found\n");
    }
    return 0;
}
*/
