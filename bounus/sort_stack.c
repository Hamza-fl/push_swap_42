/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:36 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:14:36 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sort_three_stack_a_b(t_stacks *stack, int len);
int	mediane_of_numbers(int *med_numb, int *stack, int size);
int	sort_stack_b(t_stacks *stack, int len, int count);
int	sort_three_b(t_stacks *stack, int len);

int	sort_stack_a(t_stacks *stack, int len, int count)
{
	int med_numb;
	int numbers;

	if (check_sorted(stack->a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		sort_three_stack_a_b(stack, len);
		return (1);
	}
	if (!mediane_of_numbers(&med_numb, stack->a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < med_numb && (len--))
			push_b(stack, 0);
		else if (++count)
			rotate_a(stack, 0);
	}
	while (stack->size_a != numbers / 2 + numbers % 2 && count--)
		reverse_rotate_a(stack, 0);
	return (sort_stack_a(stack, numbers / 2 + numbers % 2, 0) && sort_stack_b(stack, numbers / 2, 0));
}

int	sort_stack_b(t_stacks *stack, int len, int count)
{
	int med_numb;
	int numbers;

	if (check_sorted(stack->b, len, 1) == 1)
		while (len--)
			push_a(stack, 0);
	if (len <= 3)
	{
		sort_three_b(stack, len);
		return (1);
	}
	numbers = len;
	if (!mediane_of_numbers(&med_numb, stack->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->b[0] >= med_numb && len--)
			push_a(stack, 0);
		else if (++count)
			rotate_b(stack, 0);
	}
	while (stack->size_b != numbers / 2 && count--)
		reverse_rotate_b(stack, 0);
	return (sort_stack_a(stack, numbers / 2 + numbers % 2, 0) && sort_stack_b(stack, numbers / 2, 0));
}

void	sort_three_stack_a_b(t_stacks *stack, int len)
{
	if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, 0);
	}
	else if (len == 3 && stack->size_a == 3)
		three_numbers_sort(stack);
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0] && stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len++)
				push_a(stack, 0);
		}
	}
}

int	sort_three_b(t_stacks *stack, int len)
{
	if (len == 1)
		push_a(stack, 0);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack, 0);
		while (len--)
			push_a(stack, 0);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1]) || (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack, 0);
		}
	}
	return (0);
}

int	mediane_of_numbers(int *med_numb, int *stack, int size)
{
	int *tmp_stack;
	int i;

	tmp_stack = (int *)malloc(sizeof(int) * size);
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	tmp_sort(tmp_stack, size);
	*med_numb = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}