/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:26:16 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 11:27:35 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

# define ALLOC_ERROR_MSG "Error Allocating New Memory\n"

typedef struct s_gc_ptr
{
	void	*ptr;
}	t_gc_ptr;

typedef struct s_gc_data
{
	int			nb_items;
	size_t		original_size;
	t_gc_ptr	*data;
}	t_gc_data;

void	*gc_realloc(void *ptr, size_t original_size, size_t new_size);
void	*gc_memcpy(void *dest, const void *src, size_t n);
size_t	gc_strlen(const char *s);
char	*gc_strdup(char *str);

void	*gc_malloc(unsigned int size);
void	gc_clean_all(void);

#endif
