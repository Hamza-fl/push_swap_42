/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:41 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:14:41 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers_sort(t_stacks *stack);

int	sort(t_stacks *stack, int size)
{
	if (check_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack, 0);
		else if (size == 3)
			three_numbers_sort(stack);
		else
			sort_stack_a(stack, size, 0);
	}
	return (0);
}

int	check_sorted(int *a, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (a[i - 1] > a[i])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			if (a[i - 1] < a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	three_numbers_sort(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] < stack->a[2])
		swap_a(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack, 0);
		reverse_rotate_a(stack, 0);
	}
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
		rotate_a(stack, 0);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
		reverse_rotate_a(stack, 0);
}

void	tmp_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_push(t_stacks *stack, int len, int push)
{
	if (push == 0)
		push_b(stack, 0);
	else
		push_a(stack, 0);
	len--;
	return (len);
}
