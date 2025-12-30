/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:52:48 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:52:49 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
//     char *r = ft_strrchr("banana", 'a');
//     if (r) printf("%s", r);
//     return 0;
// }
