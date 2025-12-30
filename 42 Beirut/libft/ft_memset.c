/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:52:10 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 12:52:11 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	ptr = (unsigned char *)s;
	val = c;
	i = 0;
	while (i < n)
	{
		ptr[i] = val;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// int main(void)
// {
//     char a[10];
//     ft_memset(a, 'X', 5);
//     a[5] = 0;
//     printf("%s", a);
//     return 0;
// }
