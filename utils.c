#include "push_swap.h"

int	check_b(t_node *main)
{
	int d;
	t_node *tmp;

	if (main->next == main || main->is_empty)
		return (1);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data > d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

int check_a(t_node *main)
{
	int d;
	t_node *tmp;

	if (main->next == main || main->is_empty)
		return (0);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data < d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

int	check(t_node *main, t_node *b)
{
	int d;
	t_node *tmp;

	if (!b->is_empty)
		return (0);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data < d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

void	init_p(void (*p[12])(t_node **a, t_node **b))
{
	p[0] = swap_a;
	p[1] = rotate_a;
	p[2] = reverse_a;
	p[3] = push_b;
	p[4] = push_a;
	p[5] = swap_b;
	p[6] = rotate_b;
	p[7] = reverse_b;
	p[8] = swap_s;
	p[9] = rotate_s;
	p[10] = reverse_s;
	p[11] = NULL;
}

void	init_ops(char *ops[11])
{
	ops[0] = "SA";
	ops[1] = "RA";
	ops[2] = "RRA";
	ops[3] = "PB";
	ops[4] = "PA";
	ops[5] = "SB";
	ops[6] = "RB";
	ops[7] = "RRB";
	ops[8] = "SS";
	ops[9] = "RR";
	ops[10] = "RRR";
}
