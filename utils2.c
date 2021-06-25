#include "push_swap.h"

void	init_main(t_node **main, char **av, t_utils *utils)
{
	int		i;
	t_node	*new;

	i = 2;
	(*main) = m_malloc(sizeof(t_node), utils);
	(*main)->data = ft_atoi(av[1]);
	error_and_exit(av[1], (*main)->data);
	(*main)->next = *main;
	(*main)->prev = *main;
	(*main)->is_empty = 0;
	while (av[i])
	{
		new = m_malloc(sizeof(t_node), utils);
		new->data = ft_atoi(av[i]);
		error_and_exit(av[i], new->data);
		add_last(main, new);
		i++;
	}
}

void	init_stack_b(t_node **b, t_utils *utils)
{
	(*b) = m_malloc(sizeof(t_node), utils);
	(*b)->data = 0;
	(*b)->next = *b;
	(*b)->prev = *b;
	(*b)->is_empty = 1;
}

void	add_last(t_node **main, t_node *new)
{
	t_node	*tmp;

	if (new->data == (*main)->data)
		error_and_exit(NULL, 0);
	if ((*main)->next == *main)
	{
		(*main)->next = new;
		(*main)->prev = new;
		new->prev = *main;
		new->next = *main;
		return ;
	}
	tmp = (*main)->next;
	while (tmp->next != *main)
	{
		if (new->data == tmp->data || new->data == tmp->next->data)
			error_and_exit(NULL, 0);
		tmp = tmp->next;
	}
	(*main)->prev = new;
	tmp->next = new;
	new->prev = tmp;
	new->next = *main;
}

void	assign_for_norm(int *j, t_utils *utils, int for_j, int for_b)
{
	*j = for_j;
	utils->is_b = for_b;
	if (!for_b)
		utils->chunk = m_malloc(utils->chunk_size * sizeof(int), utils);
}
