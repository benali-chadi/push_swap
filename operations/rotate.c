#include "../push_swap.h"

void	ft_rotate(t_node **main)
{
	int	is_empty;

	if ((*main)->next != *main)
	{
		is_empty = (*main)->is_empty;
		*main = (*main)->next;
		(*main)->is_empty = is_empty;
	}
}

char	*rotate_a(t_node **a, t_node **b, t_utils *utils)
{
	(void)utils;
	(void)b;
	ft_rotate(a);
	return ("ra\n");
}

char	*rotate_b(t_node **a, t_node **b, t_utils *utils)
{
	(void)utils;
	(void)a;
	ft_rotate(b);
	return ("rb\n");
}

char	*rotate_s(t_node **a, t_node **b, t_utils *utils)
{
	(void)utils;
	ft_rotate(a);
	ft_rotate(b);
	return ("rr\n");
}
