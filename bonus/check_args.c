/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:59:13 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/17 11:12:56 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	empty(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i] && av[i][0] != '\0')
		i++;
	if (i != ac)
		return (0);
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	basic_check(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!empty(ac, av))
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
