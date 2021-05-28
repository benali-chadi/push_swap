#include "push_swap.h"

// Swap func

void	swap(t_node **main, t_node **b)
{
	int	tmp;

	if (!(*main)->next)
		return ;
	tmp = (*main)->data;
	(*main)->data = (*main)->next->data;
	(*main)->next->data = tmp;

	if (b && (*b)->next)
	{
		tmp = (*b)->data;
		(*b)->data = (*b)->next->data;
		(*b)->next->data = tmp;
	}
}

// Push func

void	push(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		data;

	tmp = NULL;
	if ((*a)->is_empty)
		return ;
	data = (*a)->data;
	if (!(*a)->next)
	{
		(*a)->data = 0;
		(*a)->is_empty = 1;
	}
	else
		tmp = (*a)->next;
	if ((*a)->next->next != *a)
	{
		(*a)->next = (*a)->next->next;
		(*a)->data = (*a)->next->data;
	}
	else
	{
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	if (tmp)
		free(tmp);
	
	if ((*b)->is_empty)
	{
		(*b)->data = data;
		(*b)->is_empty = 0;
	}
	else
	{
		tmp = malloc(sizeof(t_node));
		tmp->data = data;
		if (!(*b)->next)
		{
			tmp->next = (*b);
			tmp->prev = (*b);
			(*b)->next = tmp;
			(*b)->prev = tmp;
		}
		else
		{
			tmp->next = (*b)->next;
			tmp->prev = *b;
			(*b)->next = tmp;
		}
		swap(b, NULL);
	}
	
}

// Rotate func
// Reverse func