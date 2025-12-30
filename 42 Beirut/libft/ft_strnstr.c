/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:37:49 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:37:50 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		if (i + little_len > len)
			break ;
		j = 0;
		while ((big[j + i] == little[j]) && j < little_len)
			j++;
		if (j == little_len)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
//     char *r = ft_strnstr("hello world", "wor", 11);
//     if (r) printf("%s", r);
//     return 0;
// }
