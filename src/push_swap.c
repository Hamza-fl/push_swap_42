/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:04 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:14:04 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	char *s;
	char **str;

	if (ac > 1)
	{
		ft_join_args(av, &s);
		str = ft_split(s, ' ');
		push_swap(str);
		free(s);
	}
	int size = push_swap_len(str);
	int i = -1;
	if (ac >= 2)
	{
		while (++i < size)
			free(str[i]);
		free(str);
	}
	return (0);
}

void push_swap(char **av)
{
	t_stacks    stack;
	int         size;
	int         i;

	i = -1;
	size = push_swap_len(av);
	stack.a = malloc(sizeof(int) * size);
	int j = 0;
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = push_swap_atoi(av[i], stack.a);
	check_doubles(stack.a, size);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}
