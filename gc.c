/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:27:50 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 10:47:22 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gc.h>

static void	*gc_add_alloc(unsigned int size, t_gc_data	*gc_data)
{
	if (gc_data->data == NULL)
		gc_data->data = (t_gc_ptr *) malloc(1 * size * sizeof(t_gc_ptr));
	else
		gc_data->data = gc_realloc(gc_data->data, \
			gc_data->original_size, (gc_data->nb_items + 1) \
				* size * sizeof(t_gc_ptr));
	if (gc_data->data == NULL)
	{
		write(2, ALLOC_ERROR_MSG, gc_strlen(ALLOC_ERROR_MSG));
		exit(1);
	}
	gc_data->original_size = (gc_data->nb_items + 1) * sizeof(t_gc_data);
	gc_data->data[gc_data->nb_items].ptr = malloc(size);
	if (gc_data->data[gc_data->nb_items].ptr == NULL)
	{
		write(2, ALLOC_ERROR_MSG, gc_strlen(ALLOC_ERROR_MSG));
		exit(1);
	}
	gc_data->nb_items++;
	return (gc_data->data[gc_data->nb_items - 1].ptr);
}

static void	gc_cleanup(t_gc_data *gc_data)
{
	while (gc_data->nb_items - 1 >= 0)
	{
		if (gc_data->data != NULL && \
			gc_data->data[gc_data->nb_items - 1].ptr != NULL)
			free(gc_data->data[gc_data->nb_items - 1].ptr);
		gc_data->nb_items--;
	}
	free(gc_data->data);
	gc_data->data = NULL;
}

static void	*gc_core(unsigned int size, bool should_cleanup)
{
	static t_gc_data	gc_data;

	if (should_cleanup)
	{
		gc_cleanup(&gc_data);
		return (NULL);
	}
	return (gc_add_alloc(size, &gc_data));
}

void	*gc_malloc(unsigned int size)
{
	return (gc_core(size, false));
}

void	gc_clean_all(void)
{
	(void) gc_core(0, true);
}
