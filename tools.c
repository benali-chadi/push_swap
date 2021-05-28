#include "push_swap.h"

// Swap func

void	ft_swap(t_node **main, t_node **b)
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

void	ft_push(t_node **a, t_node **b)
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
	if ((*a)->next && (*a)->next->next != *a)
	{
		(*a)->data = (*a)->next->data;
		(*a)->next = (*a)->next->next;
	}
	else
	{
		if ((*a)->next)
			(*a)->data = (*a)->next->data;
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
		ft_swap(b, NULL);
	}
	
}

// Rotate func

void	ft_rotate(t_node **main, t_node **b)
{
	int is_empty;

	if ((*main)->prev)
	{
		is_empty = (*main)->is_empty;
		*main = (*main)->prev;
		(*main)->is_empty = is_empty;
	}

	if (*b && (*b)->prev)
	{
		is_empty = (*b)->is_empty;
		*b = (*b)->prev;
		(*b)->is_empty = is_empty;
	}
}

// Reverse func

void	ft_reverse(t_node **main, t_node **b)
{
	int is_empty;

	if ((*main)->next)
	{
		is_empty = (*main)->is_empty;
		*main = (*main)->next;
		(*main)->is_empty = is_empty;
	}

	if (*b && (*b)->next)
	{
		is_empty = (*b)->is_empty;
		*b = (*b)->next;
		(*b)->is_empty = is_empty;
	}
}