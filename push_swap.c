#include "push_swap.h"

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

int	check(t_node *main)
{
	int d;
	t_node *tmp;

	d = main->data;
	tmp = main->next;
	while (tmp->next != main)
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

int main(int ac, char **av)
{
	int i;
	t_node *main;
	t_node *main_b;
	void (*p[12]) (t_node **a, t_node **b);
	init_p(p);

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
		p[PA](&main, &main_b);
		p[PA](&main, &main_b);
		p[PA](&main, &main_b);
		p[PA](&main, &main_b);

		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);
		
		printf("\nAfter 2 Rotations\n");
		p[RR](&main, &main_b);
		p[RR](&main, &main_b);
		
		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);

		printf("\nAfter 1 reverse\n");

		p[RRR](&main, &main_b);
		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);
	}
	return (0);
}
