/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:00:56 by iavautra          #+#    #+#             */
/*   Updated: 2024/07/10 11:15:29 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

bool	extract_map_info(t_map_info *map_info, char *line)
{
	int			has_error;

	map_info->height = ft_atoi(line, &has_error);
	if (has_error)
		return (false);
	if (ft_strlen(line) <= 3)
		return (false);
	map_info->fill = line[ft_strlen(line) - 2];
	map_info->obstacle = line[ft_strlen(line) - 3];
	map_info->empty = line[ft_strlen(line) - 4];
	return (true);
}

bool	read_map(int fd, t_full_map *full_map)
{
	char	*line;
	char	*tmp;
	int		i;

	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	full_map->info.width = ft_strlen(line) - 1;
	if (full_map->info.width == 0 || full_map->info.height == 0)
	{
		free(line);
		return (false);
	}
	full_map->map = (t_map) gc_malloc((unsigned int) full_map->info.height * \
	full_map->info.width * sizeof(t_map));
	i = 0;
	while (line != NULL && i < full_map->info.height)
	{
		if ((int) ft_strlen(line) - 1 != full_map->info.width)
		{
			free(line);
			full_map->info.height = i;
			return (false);
		}
		full_map->map[i] = gc_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	if (line != NULL)
		free(line);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		free(tmp);
	}
	full_map->info.height = i;
	return (true);
}

bool	parse_map(char *file_path, t_full_map *full_map)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	if (!extract_map_info(&full_map->info, line))
		return (false);
	if (!read_map(fd, full_map))
		return (false);
	if (close(fd) == -1)
		return (false);
	free(line);
	return (true);
}
