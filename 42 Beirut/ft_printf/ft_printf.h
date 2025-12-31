/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:04:11 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/12/29 17:04:12 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunsignednbr(unsigned int n);
int		ft_puthex(unsigned int n, const char *base);
int		ft_putptr(void *ptr);
int		helper(char character, va_list *argptr);
int		ft_printf(const char *input, ...);

#endif