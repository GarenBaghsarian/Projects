/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:02:39 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/12/29 17:02:39 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex(unsigned int num, const char *base, int base_len)
{
	int				count;
	char			*result;
	unsigned int	temp;

	temp = num;
	count = 0;
	if (num == 0)
		count = 1;
	while (temp)
	{
		temp /= base_len;
		count++;
	}
	result = (char *)malloc(count + 1);
	if (!result)
		return (NULL);
	result[0] = base[0];
	result[count] = '\0';
	while (num > 0)
	{
		result[--count] = base[num % base_len];
		num /= base_len;
	}
	return (result);
}

int	ft_puthex(unsigned int n, const char *base)
{
	char	*str;
	int		count;

	str = hex(n, base, ft_strlen(base));
	if (!str)
		return (0);
	count = ft_putstr(str);
	free(str);
	return (count);
}

static int	ft_putptr_hex(size_t n)
{
	const char	*base;
	int			count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	ft_putchar(base[n % 16]);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putptr_hex(*((size_t *)&ptr));
	return (count);
}
