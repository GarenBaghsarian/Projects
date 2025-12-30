/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:56:49 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:56:50 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src)
{
	size_t		length;
	size_t		i;
	char		*result;

	length = 0;
	while (src[length])
		length++;
	result = (char *)(malloc(length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>
// int main(void)
// {
//     char *dup = ft_strdup("hello");
//     printf("%s", dup);
//     free(dup);
//     return 0;
// }
