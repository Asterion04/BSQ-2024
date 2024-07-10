/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:13:07 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 16:02:09 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	apply_square(t_full_map full_map, int best_x, int best_y, int best_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < full_map.info.height)
	{
		j = 0;
		while (j < full_map.info.width)
		{
			if ((i > best_x - best_size && j > (best_y - best_size)) \
				&& (i < best_x + 1 && j < best_y + 1))
				full_map.map[i][j] = full_map.info.fill;
			j++;
		}
		i++;
	}
}

int	*find_best_xy(int rows, int cols, int max_side, int **dp)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (dp[x][y] == max_side)
				break ;
			y++;
		}
		if (y < cols && dp[x][y] == max_side)
			break ;
		x++;
	}
	return ((int []){x, y});
}

void	find_max_side(int *ij, t_full_map full_map, int **dp, int *max_side)
{
	int			j;
	int			i;

	i = ij[0];
	j = ij[1];
	if (full_map.map[i][j] == full_map.info.empty)
	{
		if (i == 0 || j == 0)
		{
			if (full_map.map[i][j] == full_map.info.empty)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
		else
			dp[i][j] = ft_min((int []){dp[i - 1][j], dp[i][j - 1], \
				dp[i - 1][j - 1], -1}) + 1;
		*max_side = ft_max(*max_side, dp[i][j]);
	}
}

bool	solve(t_full_map full_map)
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

bool	try_solving_map(char *file_path)
{
	t_full_map	full_map;
	bool		has_error;

	has_error = false;
	if (!parse_map(file_path, &full_map))
		return (false);
	if (!is_map_valid(full_map))
		has_error = true;
	if (!has_error && !solve(full_map))
		has_error = true;
	return (!has_error);
}
