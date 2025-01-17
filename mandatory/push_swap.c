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

short	basic_check(int ac, char **nums);
short	empty(int ac, char **nums);
void	free_str(char **str, int size);

int	main(int ac, char **av)
{
	char	*s;
	char	**str;
	int		size;

	str = NULL;
	if (basic_check(ac, av) == 0)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	if (ac > 1)
	{
		ft_join_args(av, &s);
		str = ft_split(s, ' ');
		push_swap(str);
		free(s);
	}
	if (!str)
		return (0);
	size = push_swap_len(str);
	if (ac >= 2)
		free_str(str, size);
	return (0);
}

void	push_swap(char **av)
{
	t_stacks	stack;
	int			size;
	int			i;

	i = -1;
	size = push_swap_len(av);
	stack.a = malloc(sizeof(int) * size);
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

short	empty(int ac, char **nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nums[i] && nums[i][0] != '\0')
		i++;
	if (i != ac)
		return (0);
	i = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j] == ' ')
			j++;
		if (nums[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

short	basic_check(int ac, char **nums)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!empty(ac, nums))
			return (0);
		i++;
	}
	return (1);
}

void	free_str(char **str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(str[i]);
	free(str);
}
