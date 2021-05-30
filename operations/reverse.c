#include "../push_swap.h"

void	ft_reverse(t_node **main)
{
	int	is_empty;

	if ((*main)->next)
	{
		is_empty = (*main)->is_empty;
		*main = (*main)->next;
		(*main)->is_empty = is_empty;
	}
}

void    reverse_a(t_node **a, t_node **b)
{
    (void)b;
    ft_reverse(a);
}

void    reverse_b(t_node **a, t_node **b)
{
    (void)a;
    ft_reverse(b);
}

void    reverse_s(t_node **a, t_node **b)
{
    ft_reverse(a);
    ft_reverse(b);
}