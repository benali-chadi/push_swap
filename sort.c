#include "push_swap.h"

int	sort(t_node *a, t_node *b, void (*p[12])(t_node **a, t_node **b), int val)
{
	if (check(a, b))
	{
		printf("a:\n");
		print_stack(a);
		printf("b:\n");
		print_stack(b);
		return (1);
	}
	// printf("ok\n");

	while (!a->is_empty)
	{
		p[val](&a, &b);
		if (sort(a, b, p, rand() % 11) || sort(a, b, p, rand() % 11))
			return (1);
	}
	return (0);
}