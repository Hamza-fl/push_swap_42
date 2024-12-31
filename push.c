#include "push_swap.h"

void	push_a(t_stacks *stack, int bonus)
{
    int i;

    if (stack->size_b)
    {
        stack->size_a++;
        i = stack->size_a;
        while (i-- > 0)
            stack->a[i] = stack->a[i - 1];
        stack->a[0] = stack->b[0];
        stack->size_b--;
        i = -1;
        while (i++ < stack->size_b)
            stack->b[i] = stack->b[i + 1];
        if (!bonus)
            write (1, "pa\n", 3);
    }
    else
        return ;
}

void	push_b(t_stacks *stack, int bonus)
{
    int i;

    if (stack->size_a)
    {
        stack->size_b++;
        i = stack->size_b;
        while (i-- > 0)
            stack->b[i] = stack->b[i - 1];
        stack->b[0] = stack->a[0];
        stack->size_a--;
        i = -1;
        while (i++ < stack->size_a)
            stack->a[i] = stack->a[i + 1];
        if (!bonus)
            write (1, "pb\n", 3);
    }
    else
        return ;
}