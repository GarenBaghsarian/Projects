/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:18:23 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/11/04 13:18:24 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		target;

	p = s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*p == target)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
//     char s[] = "hello world";
//     char *p = ft_memchr(s, 'o', 11);
//     if (p) printf("%s", p);
//     return 0;
// }
