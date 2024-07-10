/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:49:47 by iavautra          #+#    #+#             */
/*   Updated: 2024/07/10 16:01:34 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

static bool	loop_line_map_stdin(int fd, char *line, t_full_map *full_map)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	while (line != NULL && ++i < full_map->info.height - 1)
	{
		full_map->map[i] = gc_strdup(line);
		line = get_next_line(fd);
		if ((int) ft_strlen(line) - 1 != full_map->info.width)
		{
			free(line);
			full_map->info.height = i;
			return (false);
		}
	}
	if (line != NULL)
		full_map->map[i] = gc_strdup(line);
	return (true);
}

static bool	read_map_stdin(int fd, t_full_map *full_map)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	full_map->info.width = ft_strlen(line) - 1;
	if (full_map->info.width == 0 || full_map->info.height == 0)
	{
		free(line);
		return (false);
	}
	full_map->map = (t_map) gc_malloc((unsigned int)full_map->info.height * \
	full_map->info.width * sizeof(t_map));
	if (!loop_line_map_stdin(fd, line, full_map))
		return (false);
	return (true);
}

bool	parse_map_stdin(t_full_map *full_map)
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
	return (read_map_stdin(fd, full_map));
}
