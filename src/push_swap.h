/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:14:04 by hfalati           #+#    #+#             */
/*   Updated: 2025/01/14 15:59:15 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;



int		ft_strcmp(char *s1, char *s2);
void	push_swap(char **av);
char	**ft_split(char const *s, char c);
int		push_swap_len(char **av);
int		push_swap_atoi(char *av, int *stack);
void	ft_join_args(char **av, char **str);
size_t	ft_strlen(const char *str);

int		sort(t_stacks *stack, int size);
int		sort_stack_a(t_stacks *stack, int len, int count);

void	error_detected(int *stack);
void	check_doubles(int *stack, int size);
int		check_sorted(int *a, int size, int order);
int		ft_push(t_stacks *stack, int len, int push);

void	three_numbers_sort(t_stacks *stack);

void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	swap_s(t_stacks *stack);

void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_r(t_stacks *stack);

void	reverse_rotate_a(t_stacks *stack);
void	reverse_rotate_b(t_stacks *stack);
void	reverse_rotate_r(t_stacks *stack);

void	tmp_sort(int *tmp_stack, int size);
#endif