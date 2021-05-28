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

int main(int ac, char **av)
{
	int i;
	t_node *main;
	t_node *main_b;

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
		ft_push(&main, &main_b);
		ft_push(&main, &main_b);
		ft_push(&main, &main_b);
		
		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);
		
		printf("\nAfter 2 Rotations\n");

		ft_rotate(&main, &main_b);
		ft_rotate(&main, &main_b);
		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);

		printf("\nAfter 1 reverse\n");

		ft_reverse(&main, &main_b);
		printf("stack a\n");
		print_stack(main);
		printf("\nstack b\n");
		print_stack(main_b);
	}
	return (0);
}
