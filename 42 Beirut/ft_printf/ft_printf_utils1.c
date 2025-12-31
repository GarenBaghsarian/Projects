/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:02:25 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/12/29 17:02:26 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count++;
	ft_putchar((num % 10) + '0');
	return (count);
}

int	ft_putunsignednbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsignednbr(n / 10);
	count++;
	ft_putchar((n % 10) + '0');
	return (count);
}
