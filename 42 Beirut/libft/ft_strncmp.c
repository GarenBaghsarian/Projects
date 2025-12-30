/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:16:15 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:19:04 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// #include <stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_strncmp("hello", "hela",3));
// 	printf("%d\n", ft_strncmp("hello", "hela",4));
// 	printf("%d\n", ft_strncmp("hello", "helz",5));
// 	return 0;
// }
