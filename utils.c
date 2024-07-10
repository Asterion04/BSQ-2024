/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:59:50 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 11:10:41 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*dst;
	size_t	cnt;

	str1 = (char *) s1;
	str2 = (char *) s2;
	cnt = 0;
	dst = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (*str1 != '\0')
	{
		dst[cnt] = *str1;
		str1++;
		cnt++;
	}
	while (*str2 != '\0')
	{
		dst[cnt] = *str2;
		str2++;
		cnt++;
	}
	dst[cnt] = '\0';
	return (dst);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	if (c == 0)
		return (s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_atoi(const char *str, int *has_error)
{
	int		i;
	int		result;
	char	*s;

	s = (char *) str;
	i = 0;
	result = 0;
	*has_error = 0;
	if (s[i] < '0' || s[i] > '9')
	{
		*has_error = 1;
		return (0);
	}
	if (ft_strlen(str) <= 4)
	{
		*has_error = 1;
		return (0);
	}
	while (s[i] >= '0' && s[i] <= '9' && i < (int) ft_strlen(str) - 4)
		result = result * 10 + (s[i++] - '0');
	return (result);
}

void	print_map(t_full_map full_map)
{
	int	i;

	i = 0;
	while (i < full_map.info.height)
	{
		write(1, full_map.map[i], full_map.info.width);
		if (i + 1 < full_map.info.height)
			ft_putchar('\n');
		i++;
	}
}
