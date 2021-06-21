#include "push_swap.h"

void	init_main(t_node **main, char **av)
{
	int		i;
	t_node	*new;

	i = 2;
	(*main) = malloc(sizeof(t_node));
	(*main)->data = ft_atoi(av[1]);
	error_and_exit(av[1], (*main)->data);
	(*main)->next = *main;
	(*main)->prev = *main;
	(*main)->is_empty = 0;
	while (av[i])
	{
		new = malloc(sizeof(t_node));
		new->data = ft_atoi(av[i]);
		error_and_exit(av[i], new->data);
		add_last(main, new);
		i++;
	}	
}

void	init_stack_b(t_node **b)
{
	(*b) = malloc(sizeof(t_node));
	(*b)->data = 0;
	(*b)->next = *b;
	(*b)->prev = *b;
	(*b)->is_empty = 1;
}

void	add_last(t_node **main, t_node *new)
{
	t_node	*tmp;

	if ((*main)->next == *main)
	{
		(*main)->next = new;
		(*main)->prev = new;
		new->prev = *main;
		new->next = *main;
		return ;
	}
	if (new->data == (*main)->data)
		error_and_exit(NULL, 0);
	tmp = (*main)->next;
	while (tmp->next != *main)
	{
		if (new->data == tmp->data)
			error_and_exit(NULL, 0);
		tmp = tmp->next;
	}
	(*main)->prev = new;
	tmp->next = new;
	new->prev = tmp;
	new->next = *main;
}