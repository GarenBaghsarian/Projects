/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:22:12 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/12/29 17:22:13 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int helper(char character, va_list *argptr)
{
	int c;

	c = 0;
	if (!character)
		return (c);
	if (character == 'c')
		c += ft_putchar((char)va_arg(*argptr, int));
	else if (character == 's')
		c += ft_putstr(va_arg(*argptr, char *));
	else if (character == 'd' || character == 'i')
		c += ft_putnbr(va_arg(*argptr, int));
	else if (character == 'u')
		c += ft_putunsignednbr(va_arg(*argptr, unsigned int));
	else if (character == '%')
		c += ft_putchar('%');
	else if (character == 'x')
		c += ft_puthex(va_arg(*argptr, unsigned int), "0123456789abcdef");
	else if (character == 'X')
		c += ft_puthex(va_arg(*argptr, unsigned int), "0123456789ABCDEF");
	else if (character == 'p')
		c += ft_putptr(va_arg(*argptr, void *));
	return (c);
}

int ft_printf(const char *input, ...)
{
	int i;
	int count;
	va_list argptr;

	i = 0;
	count = 0;
	va_start(argptr, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (!input[i])
				break;
			count += helper(input[i], &argptr);
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	va_end(argptr);
	return (count);
}

// #include <limits.h>
// int main(void)
// {
// 	int ft_count, std_count;
// 	int num = 42;
// 	int neg = -42;
// 	unsigned int unum = 4294967295U;
// 	char ch = 'A';
// 	char *str = "Hello World";
// 	char *null_str = NULL;
// 	int hex = 0xABC;
// 	int small_hex = 0;
// 	int ptr_test = 123;
// 	void *ptr = &ptr_test;
// 	void *null_ptr = NULL;

// 	printf("=== Testing ft_printf ===\n\n");

// 	// Test 1: Basic characters and strings
// 	printf("Test 1: Basic characters and strings\n");
// 	ft_count = ft_printf("Char: %c, String: %s\n", ch, str);
// 	std_count = printf("Char: %c, String: %s\n", ch, str);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 2: NULL string
// 	printf("Test 2: NULL string\n");
// 	ft_count = ft_printf("NULL string: %s\n", null_str);
// 	std_count = printf("NULL string: %s\n", null_str);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 3: Signed integers
// 	printf("Test 3: Signed integers\n");
// 	ft_count = ft_printf("Positive: %d, Negative: %i, Zero: %d\n", num, neg, 0);
// 	std_count = printf("Positive: %d, Negative: %i, Zero: %d\n", num, neg, 0);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 4: Unsigned integers
// 	printf("Test 4: Unsigned integers\n");
// 	ft_count = ft_printf("Unsigned: %u, Max unsigned: %u\n", num, unum);
// 	std_count = printf("Unsigned: %u, Max unsigned: %u\n", num, unum);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 5: Hexadecimal (lowercase)
// 	printf("Test 5: Hexadecimal lowercase\n");
// 	ft_count = ft_printf("Hex: %x, Small: %x, Max: %x\n", hex, small_hex, unum);
// 	std_count = printf("Hex: %x, Small: %x, Max: %x\n", hex, small_hex, unum);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 6: Hexadecimal (uppercase)
// 	printf("Test 6: Hexadecimal uppercase\n");
// 	ft_count = ft_printf("Hex: %X, Small: %X, Max: %X\n", hex, small_hex, unum);
// 	std_count = printf("Hex: %X, Small: %X, Max: %X\n", hex, small_hex, unum);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 7: Percent sign
// 	printf("Test 7: Percent sign\n");
// 	ft_count = ft_printf("100%% complete, %% sign: %%\n");
// 	std_count = printf("100%% complete, %% sign: %%\n");
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 8: Pointers
// 	printf("Test 8: Pointers\n");
// 	ft_count = ft_printf("Pointer: %p, NULL pointer: %p\n", ptr, null_ptr);
// 	std_count = printf("Pointer: %p, NULL pointer: %p\n", ptr, null_ptr);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 9: Mixed format
// 	printf("Test 9: Mixed format\n");
// 	ft_count = ft_printf("Mixed: %c %s %d %i %u %x %X %% %p\n",
// 						 ch, str, num, neg, unum, hex, hex, ptr);
// 	std_count = printf("Mixed: %c %s %d %i %u %x %X %% %p\n",
// 					   ch, str, num, neg, unum, hex, hex, ptr);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 10: Edge cases with INT_MIN and INT_MAX
// 	printf("Test 10: Edge cases\n");
// 	ft_count = ft_printf("INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n",
// 						 INT_MIN, INT_MAX, UINT_MAX);
// 	std_count = printf("INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n",
// 					   INT_MIN, INT_MAX, UINT_MAX);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 11: Empty string and no conversions
// 	printf("Test 11: No conversions\n");
// 	ft_count = ft_printf("Just a regular string without conversions\n");
// 	std_count = printf("Just a regular string without conversions\n");
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 12: Character with ASCII 0
// 	printf("Test 12: Character with ASCII 0\n");
// 	ft_count = ft_printf("Null char: %c end\n", '\0');
// 	std_count = printf("Null char: %c end\n", '\0');
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 13: Multiple percent signs
// 	printf("Test 13: Multiple percent signs\n");
// 	ft_count = ft_printf("%%%% %%%%%% %c\n", ch);
// 	std_count = printf("%%%% %%%%%% %c\n", ch);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	// Test 14: Pointer to different types
// 	printf("Test 14: Different pointer types\n");
// 	char char_var = 'X';
// 	int int_var = 42;
// 	ft_count = ft_printf("Char ptr: %p, Int ptr: %p, String ptr: %p\n",
// 						 &char_var, &int_var, str);
// 	std_count = printf("Char ptr: %p, Int ptr: %p, String ptr: %p\n",
// 					   &char_var, &int_var, str);
// 	printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

// 	printf("=== All tests completed ===\n");

// 	return 0;
// }