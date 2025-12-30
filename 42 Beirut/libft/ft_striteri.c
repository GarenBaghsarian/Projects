/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:37:02 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/11/22 12:37:04 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>
// void f(unsigned int i, char *c)
// {
//     *c = *c + 1;
// }
// int main(void)
// {
//     char s[] = "abc";
//     ft_striteri(s, f);
//     printf("%s", s);
//     return 0;
// }
