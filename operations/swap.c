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

char	*swap_a(t_node **a, t_node **b, t_utils *utils)
{
	(void)b;
	(void)utils;
	ft_swap(a);
	return ("sa\n");
}

char	*swap_b(t_node **a, t_node **b, t_utils *utils)
{
	(void)a;
	(void)utils;
	ft_swap(b);
	return ("sb\n");
}

char	*swap_s(t_node **a, t_node **b, t_utils *utils)
{
	(void)utils;
	ft_swap(a);
	ft_swap(b);
	return ("ss\n");
}
