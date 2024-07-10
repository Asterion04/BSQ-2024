/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:04:21 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 10:23:41 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int *values)
{
	int	min;
	int	i;

	min = values[0];
	if (min < 0)
		return (0);
	i = 0;
	while (values[i] != -1)
	{
		if (values[i] < min)
			min = values[i];
		i++;
	}
	return (min);
}

bool	is_map_valid(t_full_map	full_map)
{
	int	i;
	int	j;

	if ((int) ft_strlen(full_map.map[0]) - 1 != full_map.info.width)
		return (false);
	i = 0;
	while (i < full_map.info.height)
	{
		j = 0;
		while (j < full_map.info.width)
		{
			if (full_map.map[i][j] != full_map.info.obstacle && \
				full_map.map[i][j] != full_map.info.empty)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
