/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 01:09:20 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 11:13:25 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static bool	parse_map_stdin(t_full_map *full_map)
{
	int		fd;
	char	*line;

	fd = STDIN_FILENO;
	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	if (!extract_map_info(&full_map->info, line))
		return (false);
	free(line);
	return (read_map(fd, full_map));
}

bool	try_solving_stdin(void)
{
	t_full_map	full_map;
	bool		has_error;

	has_error = false;
	if (!parse_map_stdin(&full_map))
		return (false);
	if (!is_map_valid(full_map))
		has_error = true;
	if (!has_error)
		ft_putchar('\n');
	if (!has_error && !solve(full_map))
		has_error = true;
	return (!has_error);
}
