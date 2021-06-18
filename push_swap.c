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

	if ((*main)->next == *main)
	{
		(*main)->next = new;
		(*main)->prev = new;
		new->prev = *main;
		new->next = *main;
		return ;
	}
	if (new->data == (*main)->data)
		error_and_exit();
	tmp = (*main)->next;
	while (tmp->next != *main)
	{
		if (new->data == tmp->data)
			error_and_exit();
		tmp = tmp->next;
	}
	
	(*main)->prev = new;
	tmp->next = new;
	new->prev = tmp;
	new->next = *main;
}

void	init_stack_b(t_node **b)
{
	(*b) = malloc(sizeof(t_node));
	(*b)->data = 0;
	(*b)->next = *b;
	(*b)->prev = *b;
	(*b)->is_empty = 1;
}

void	init_main(t_node **main, char **av)
{
	int i;
	int j;
	// int dups_p[214748];
	// int dups_n[2147483648];

	i = 2;
	(*main) = malloc(sizeof(t_node));
	// check the arg
	j = -1;
	while (av[1][++j])
		if (av[1][j] < '0' || av[1][j] > '9')
			error_and_exit();
	(*main)->data = atoi(av[1]);
	(*main)->next = *main;
	(*main)->prev = *main;
	(*main)->is_empty = 0;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				error_and_exit();
		t_node *new = malloc(sizeof(t_node));
		new->data = atoi(av[i]);
		add_last(main, new);
		i++;
	}	
}

int main(int ac, char **av)
{
	t_node *main;
	t_node *main_b;
	t_utils utils;

	init_p(utils.p);
	init_stack_b(&main_b);
	if (ac > 1)
	{
		init_main(&main, av);

		utils.arr = sort_array(main, stack_len(main));
		utils.len = stack_len(main);
		if (utils.len <= 10)
		{
			utils.chunk_size = 0;
			sort_few_nums(main, main_b, utils);
			return (0);
		}
		else if (utils.len <= 100)
			utils.chunk_size = 10;
		else
			utils.chunk_size = 40;
		sort(main, main_b, utils);
	}
	return (0);
}
