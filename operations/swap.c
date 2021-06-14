#include "../push_swap.h"

void	ft_swap(t_node **main)
{
	int	tmp;

	if ((*main)->next == *main || (*main)->is_empty)
		return ;
	tmp = (*main)->data;
	(*main)->data = (*main)->next->data;
	(*main)->next->data = tmp;
}

void    swap_a(t_node **a, t_node **b)
{
    (void)b;
    ft_swap(a);
}

void    swap_b(t_node **a, t_node **b)
{
    (void)a;
    ft_swap(b);
}

void    swap_s(t_node **a, t_node **b)
{
    ft_swap(a);
    ft_swap(b);
}