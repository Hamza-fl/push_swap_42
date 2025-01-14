/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:13:22 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/02 23:13:22 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int		*full_a(char **av);
void	read_from_stdin(t_stacks *stack);
void	exe_str(t_stacks *stack, char *str);
void	free_error(t_stacks *stack, int what);

int	main(int ac, char **av)
{
	t_stacks	stack;
	char		*s;
	char		**str;

	if (ac > 1)
	{
		ft_join_args(av, &s);
		str = ft_split(s, ' ');
		free(s);
		stack.a = full_a(str);
		if (!stack.a)
			return (0);
		stack.size_a = push_swap_len(str);
		stack.b = malloc(stack.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack.a);
			return (0);
		}
		stack.size_b = 0;
		read_from_stdin(&stack);
	}
	return (0);
}

int	*full_a(char **av)
{
	int	i;
	int	size;
	int	*a;

	size = push_swap_len(av);
	a = malloc(size * sizeof(int));
	if (!a)
		return (0);
	i = -1;
	while (++i < size)
		a[i] = push_swap_atoi(av[i], a);
	check_doubles(a, size);
	return (a);
}

void	read_from_stdin(t_stacks *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		exe_str(stack, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sorted(stack->a, stack->size_a, 0) && stack->size_b == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_error(stack, 0);
}

void	exe_str(t_stacks *stack, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap_a(stack);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(stack);
	else if (!ft_strcmp(str, "ss\n"))
		swap_s(stack);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(stack);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(stack);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_r(stack);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_a(stack);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_b(stack);
	else if (!ft_strcmp(str, "rrr\n"))
		reverse_rotate_r(stack);
	else if (!ft_strcmp(str, "pa\n"))
		push_a(stack);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(stack);
	else
		free_error(stack, 1);
}

void	free_error(t_stacks *stack, int what)
{
	free(stack->a);
	free(stack->b);
	if (what)
	{
		write (0, "Error\n", 6);
		exit(1);
	}
	exit(0);
}
