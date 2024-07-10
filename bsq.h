/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:23 by ivautrav          #+#    #+#             */
/*   Updated: 2024/07/10 11:11:52 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <gc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef char	**t_map;

typedef struct s_map_info
{
	char	obstacle;
	char	empty;
	char	fill;
	int		height;
	int		width;
}	t_map_info;

typedef struct s_full_map
{
	t_map		map;
	t_map_info	info;
}	t_full_map;

int		ft_min(int *values);
int		ft_max(int a, int b);
bool	is_map_valid(t_full_map	full_map);

bool	try_solving_map(char *file_path);

char	*ft_free(char *buffer, char *buf);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str, int *has_error);

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	free_dp(int rows, int **dp);

void	ft_putstr_fd(char *str, int fd);
void	ft_putchar(char c);
void	print_map(t_full_map full_map);

bool	read_map(int fd, t_full_map *full_map);
bool	parse_map(char *file_path, t_full_map *full_map);
bool	extract_map_info(t_map_info *map_info, char *line);

bool	try_solving_stdin(void);

bool	solve(t_full_map full_map);
void	find_max_side(int *ij, t_full_map full_map, int **dp, int *max_side);
int		*find_best_xy(int rows, int cols, int max_side, int **dp);
void	apply_square(t_full_map full_map, int best_x, int best_y, \
	int best_size);

#endif
