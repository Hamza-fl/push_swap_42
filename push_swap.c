#include "push_swap.h"

int main (int ac, char **av)
{
    if (ac > 1)
    {
        av++;
        if (ac == 2)
            av = ft_split(*av, ' ');
        push_swap(av);
        return (0);
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
