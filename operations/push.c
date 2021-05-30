# include "../push_swap.h"


static void	push_to_b(t_node **b, int data, t_node *tmp)
{
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
		ft_swap(b);
	}
}

static void	push_from_a(t_node **a, t_node *tmp)
{
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
}

void	ft_push(t_node **a, t_node **b)
{
	int		data;
	t_node	*tmp;

	tmp = NULL;
	if ((*a)->is_empty)
		return ;
	data = (*a)->data;
	push_from_a(a, tmp);

	push_to_b(b, data, tmp);
}

void    push_a(t_node **a, t_node **b)
{
    ft_push(a, b);
}

void    push_b(t_node **a, t_node **b)
{
    ft_push(b, a);
}