/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:15:42 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 11:05:58 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	obj = (void *) malloc((unsigned int) count * size);
	if (obj == NULL)
		exit(1);
	ft_bzero(obj, count * size);
	return (obj);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n--)
		*(dest++) = 0;
}

void	free_dp(int rows, int **dp)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
