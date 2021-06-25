#include "../push_swap.h"

void	ft_reverse(t_node **main)
{
	int	is_empty;

	if ((*main)->prev != *main)
	{
		is_empty = (*main)->is_empty;
		*main = (*main)->prev;
		(*main)->is_empty = is_empty;
	}
}

char	*reverse_a(t_node **a, t_node **b, t_utils *utils)
{
	(void)b;
	(void)utils;
	ft_reverse(a);
	return ("rra\n");
}

char	*reverse_b(t_node **a, t_node **b, t_utils *utils)
{
	(void)a;
	(void)utils;
	ft_reverse(b);
	return ("rrb\n");
}

char	*reverse_s(t_node **a, t_node **b, t_utils *utils)
{
	(void)utils;
	ft_reverse(a);
	ft_reverse(b);
	return ("rrr\n");
}
