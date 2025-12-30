/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:54:05 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 12:54:06 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		ptr[n] = '\0';
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char a[10] = "abcdef";
//     ft_bzero(a + 2, 3);
// 	int i=0;
// 	while(i<5)
// 	{
// 		printf("%d ", a[i]);
// 		i++;
// 	}
//     return 0;
// }
