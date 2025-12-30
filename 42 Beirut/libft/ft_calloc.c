/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:10:41 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/11/22 12:10:42 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
// #include <stdio.h>
// int main(void)
// {
//     int *p = ft_calloc(5, sizeof(int));
//     int i=0;
// 	while (i<5)
// 	{
//         printf("%d ", p[i]);
// 		i++;
// 	}
//     free(p);
//     return 0;
// }
