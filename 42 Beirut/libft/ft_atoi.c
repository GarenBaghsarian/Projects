/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:22:00 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/10/28 13:22:02 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
static int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		count;

	sign = 1;
	count = 0;
	result = 0;
	while (is_space(*str))
		str++;
	while ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		if (count == 1)
			sign = 0;
		count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *str="123";
// 	char *str2="+-123a4";
// 	char *str3="-123a4";
// 	char * str4="\t\n    +123a4";
// 	printf("%d",atoi(str));
// 	printf("%d",atoi(str2));
// 	printf("%d",atoi(str3));
// 	printf("%d",atoi(str4));
// 	return 0;
// }