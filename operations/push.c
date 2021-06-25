#include "../push_swap.h"

static void	push_to_b(t_node **b, int data, t_node *tmp, t_utils **utils)
{
	tmp = m_malloc(sizeof(t_node), *utils);
	tmp->data = data;
	if ((*b)->is_empty)
	{
		(*b)->data = data;
		(*b)->is_empty = 0;
		(*b)->next = *b;
		(*b)->prev = *b;
	}
	else if ((*b)->next == *b)
	{
		tmp->next = *b;
		tmp->prev = *b;
		(*b)->next = tmp;
		(*b)->prev = tmp;
	}
	else
	{
		(*b)->next->prev = tmp;
		tmp->next = (*b)->next;
		tmp->prev = *b;
		(*b)->next = tmp;
	}
	ft_swap(b);
}

static void	push_from_a(t_node **a)
{
	if ((*a)->next == *a)
		(*a)->is_empty = 1;
	else if ((*a)->next->next != *a)
	{
		(*a)->data = (*a)->next->data;
		(*a)->next = (*a)->next->next;
		(*a)->next->prev = *a;
	}
	else
	{
		(*a)->data = (*a)->next->data;
		(*a)->next = *a;
		(*a)->prev = *a;
	}
}

void	ft_push(t_node **a, t_node **b, t_utils **utils)
{
	int		data;
	t_node	*tmp;

	tmp = NULL;
	if ((*a)->is_empty)
		return ;
	data = (*a)->data;
	push_from_a(a);
	push_to_b(b, data, tmp, utils);
}

char	*push_a(t_node **a, t_node **b, t_utils *utils)
{
	ft_push(b, a, &utils);
	return ("pa\n");
}

char	*push_b(t_node **a, t_node **b, t_utils *utils)
{
	ft_push(a, b, &utils);
	return ("pb\n");
}
