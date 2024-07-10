/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asterion <asterion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 05:01:40 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 11:27:16 by asterion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gc.h>

void	*gc_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n--)
		d[n] = s[n];
	return (dest);
}

size_t	gc_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

void	*gc_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
		return (NULL);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	if (original_size < new_size)
		copy_size = original_size;
	else
		copy_size = new_size;
	gc_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

char	*gc_strdup(char *str)
{
	char	*buffer;
	int		i;

	if (str == NULL)
		return (NULL);
	buffer = (char *) gc_malloc(gc_strlen(str) + 1);
	i = 0;
	while (str[i] != '\0')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	free(str);
	return (buffer);
}
