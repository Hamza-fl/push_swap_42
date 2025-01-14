/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:29 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:14:29 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stack)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i - 1] = tmp;
	write (1, "ra\n", 3);
}

void	rotate_b(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i - 1] = tmp;
	write (1, "rb\n", 3);
}

void	rotate_r(t_stacks *stack)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1 || stack->size_b == 0
		|| stack->size_b == 1)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (i++ < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	tmp = stack->b[0];
	i = 0;
	while (i++ < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	write (1, "rr\n", 3);
}
