/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:25 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:14:25 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stack, int bonus)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	i = 0;
	if (!bonus)
		write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_stacks *stack, int bonus)
{
	int	i;
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	if (!bonus)
		write (1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stacks *stack, int bonus)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1 || stack->size_b == 0
		|| stack->size_b == 1)
		return ;
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	i = stack->size_b -1;
	tmp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
	if (!bonus)
		write (1, "rrr\n", 4);
}
