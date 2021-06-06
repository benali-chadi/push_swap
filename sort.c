#include "push_swap.h"

int		get_last_data(t_node *main)
{
	t_node	*tmp;
	int		d;

	if (!main->next)
		return (main->data);

	d = main->next->data;
	tmp = main->next;
	while (tmp != main)
	{
		tmp = tmp->next;
		d = tmp->data;
	}
	return (d);
}

int		stack_len(t_node *main)
{
	int i;
	t_node *tmp;

	i = 0;
	if (main->is_empty)
		return (i);
	tmp = main->next;
	i++;
	while (tmp && tmp != main)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*sort_three_nums(t_node *a, t_node *b, t_utils utils)
{
	int i;

	i = 0;
	utils.operations[i] = -1;
	while (!check_a(a))
	{
		if (a->data > a->next->next->data)
		{
			utils.p[RA](&a, &b);
			printf("RA\n");
		}
		else if (a->next->data > a->next->next->data)
		{
			utils.p[RRA](&a, &b);
			printf("RRA\n");
		}
		else if (a->data > a->next->data)
		{
			utils.p[SA](&a, &b);
			printf("SA\n");
		}
	}
	printf("a:\n");
	print_stack(a);
	printf("b:\n");
	print_stack(b);
	return (a);
}

void	sort_five_nums(t_node *a, t_node *b, t_utils utils)
{
	int i;

	i = 0;
	while (!check(a, b))
	{
		if (a->data > get_last_data(a))
		{
			utils.p[RA](&a, &b);
			printf("RA\n");
		}
		else if (a->next && a->next->data > a->next->next->data)
		{
			utils.p[RRA](&a, &b);
			printf("RRA\n");
		}
		else if (a->next && a->data > a->next->data)
		{
			utils.p[SA](&a, &b);
			printf("SA\n");
		}
		else if (check_a(a) && !b->is_empty)
		{
			utils.p[PA](&a, &b);
			printf("PA\n");
		}
		else if (!a->is_empty)
		{
			utils.p[PB](&a, &b);
			printf("PB\n");
		}
		i++;
	}
	printf("i=%d\n", i);
	printf("a:\n");
	print_stack(a);
	printf("b:\n");
	print_stack(b);
}
