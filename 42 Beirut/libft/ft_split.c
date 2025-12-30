/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaghsar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:25:31 by gbaghsar          #+#    #+#             */
/*   Updated: 2025/11/22 12:25:32 by gbaghsar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word(int start, int end, const char *str)
{
	int		i;
	char	*result;

	result = (char *)malloc(end - start + 1);
	i = 0;
	while (i < end - start)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	length(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**helper(char **result, const char *str, int len, int c)
{
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	while (i < len)
	{
		while (str[start] && str[start] == c)
			start++;
		if (!str[start])
			break ;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		result[i] = word(start, end, str);
		i++;
		start = end;
	}
	result[i] = NULL;
	return (result);
}	

char	**ft_split(char const *str, char c)
{
	int		len;
	char	**result;

	if (!str)
		return (NULL);
	len = length(str, c);
	result = (char **)malloc((sizeof(char *)) * (len + 1));
	if (!result)
		return (NULL);
	result = helper(result, str, len, c);
	return (result);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *str="helloola";
// 	char sep='l';
// 	char **result=ft_split(str,sep);
// 	int i=0;
// 	while (i<length(str,sep))
// 	{
// 		printf("%s\n",result[i]);
// 		i++;
// 	}
// 	return 0;
// }