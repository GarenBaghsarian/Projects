/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:29:22 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:29:23 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int character)
{
	int		i;
	char	c;

	i = 0;
	c = (char) character;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
//     char *r = ft_strchr("hello world", 'o');
//     if (r) printf("%s", r);
//     return 0;
// }
