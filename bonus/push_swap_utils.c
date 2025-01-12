/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:13:55 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:13:55 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	push_swap_atoi(char *str, int *stack)
{
	int				i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_detected(stack);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > INT_MIN && sign == -1) || (result > INT_MAX && sign == 1))
		error_detected(stack);
	return (result * sign);
}

void	check_doubles(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				error_detected(stack);
			j++;
		}
		i++;
		j = i + 1;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	error_detected(int *stack)
{
	free(stack);
	write (1, "Error\n", 6);
	exit(1);
}
