/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iavautra <iavautra@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:08:00 by asterion          #+#    #+#             */
/*   Updated: 2024/07/10 15:57:18 by iavautra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		if (!try_solving_stdin())
			ft_putstr_fd("map error", 2);
		ft_putstr_fd("\n", 1);
		gc_clean_all();
	}
	i = 1;
	while (i < ac)
	{
		if (!try_solving_map(av[i]))
			ft_putstr_fd("map error", 2);
		if (i < ac - 1)
			ft_putstr_fd("\n", 1);
		ft_putstr_fd("\n", 1);
		i++;
		gc_clean_all();
	}
	return (0);
}
