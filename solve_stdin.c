/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 01:09:20 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 16:02:28 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static bool	is_map_valid_stdin(t_full_map	full_map)
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

static bool	solve_stdin(t_full_map full_map)
{
	int		**dp;
	int		i;
	int		j;
	int		*xy;
	int		max_side;

	dp = (int **) ft_calloc(full_map.info.height * full_map.info.width, \
		sizeof(int *));
	i = -1;
	max_side = 0;
	while (++i < full_map.info.height)
	{
		dp[i] = (int *) ft_calloc(full_map.info.width, sizeof(int));
		j = -1;
		while (++j < full_map.info.width)
			find_max_side((int []){i, j}, full_map, dp, &max_side);
	}
	xy = find_best_xy(full_map.info.height, full_map.info.width, max_side, dp);
	apply_square(full_map, xy[0], xy[1], max_side);
	print_map(full_map);
	free_dp(full_map.info.height, dp);
	return (true);
}

bool	try_solving_stdin(void)
{
	t_full_map	full_map;
	bool		has_error;

	has_error = false;
	if (!parse_map_stdin(&full_map))
		return (false);
	if (!is_map_valid_stdin(full_map))
		has_error = true;
	if (!has_error && !solve_stdin(full_map))
		has_error = true;
	return (!has_error);
}
