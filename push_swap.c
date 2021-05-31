#include "push_swap.h"

#include <time.h>

void	print_stack(t_node *main)
 {
	t_node *tmp;
	
	if (main->is_empty)
	{
		printf("empty\n");
		return ;
	}
	printf("%d\n", main->data);
	tmp = main->next;
	while (tmp && tmp != main)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	add_last(t_node **main, t_node *new)
{
	t_node *tmp;

	if (!(*main)->next)
	{
		(*main)->next = new;
		(*main)->prev = new;
		new->prev = *main;
		new->next = *main;
		return ;
	}
	tmp = (*main)->next;
	while (tmp->next != *main)
		tmp = tmp->next;
	
	(*main)->prev = new;
	tmp->next = new;
	new->prev = tmp;
	new->next = *main;
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
		// printf("data=%d\td=%d\n", tmp->data, d);
		if (tmp->data < d)
		{
			// printf("ok2\n");
			return (0);
		}
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

void	init_p(void (*p[12])(t_node **a, t_node **b))
{
	p[0] = swap_a;
	p[1] = swap_b;
	p[2] = swap_s;
	p[3] = push_a;
	p[4] = push_b;
	p[5] = rotate_a;
	p[6] = rotate_b;
	p[7] = rotate_s;
	p[8] = reverse_a;
	p[9] = reverse_b;
	p[10] = reverse_s;
	p[11] = NULL;
}

void	init_ops(char *ops[11])
{
	ops[0] = "SA";
	ops[1] = "SB";
	ops[2] = "SS";
	ops[3] = "PA";
	ops[4] = "PB";
	ops[5] = "RA";
	ops[6] = "RB";
	ops[7] = "RR";
	ops[8] = "RRA";
	ops[9] = "RRB";
	ops[10] = "RRR";
}

int main(int ac, char **av)
{
	int i;
	t_node *main;
	t_node *main_b;
	t_utils utils;
	// void (*p[12]) (t_node **a, t_node **b);
	init_p(utils.p);

	time_t t;
	// char *ops[11];
	init_ops(utils.ops);
	srand((unsigned) time(&t));

	main_b = malloc(sizeof(t_node));
	main_b->data = 0;
	main_b->next = NULL;
	main_b->prev = NULL;
	main_b->is_empty = 1;

	if (ac > 1)
	{
		i = 2;
		main = malloc(sizeof(t_node));
		main->data = atoi(av[1]);
		main->next = NULL;
		main->prev = NULL;
		main->is_empty = 0;
		while (av[i])
		{
			t_node *new = malloc(sizeof(t_node));
			new->data = atoi(av[i]);
			add_last(&main, new);
			i++;
		}
		sort(main, main_b, utils, rand() % 11, 0);
	}
	return (0);
}
