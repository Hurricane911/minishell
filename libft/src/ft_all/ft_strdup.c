/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyim <joyim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:57:47 by joyim             #+#    #+#             */
/*   Updated: 2025/07/18 16:39:53 by joyim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
*/

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (s == NULL)
	{
		dup = (char *)malloc(sizeof (char));
		dup[0] = '\0';
		return (dup);
	}
	size = (ft_strlen(s) + 1) * sizeof(char);
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, size);
	return (dup);
}
/*
int main() {
    char original[] = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    // Free the allocated memory for the duplicate string
    free(duplicate);

    return 0;
}
*/
