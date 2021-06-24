#include "push_swap.h"

int	for_b(t_node *a, t_node *b, t_utils utils)
{
	int	d;

	d = get_last_data(b);
	if (b->data < b->next->data)
	{
		ft_putstr_fd(utils.p[SB](&a, &b), 1);
		return (1);
	}
	else if (b->next->data < d)
	{
		ft_putstr_fd(utils.p[RRB](&a, &b), 1);
		return (1);
	}
	else if (b->data < d)
	{
		ft_putstr_fd(utils.p[RB](&a, &b), 1);
		return (1);
	}
	return (0);
}

t_node	*sort_few_nums(t_node *a, t_node *b, t_utils utils)
{
	int	d;

	while (!check(a, b))
	{
		d = get_last_data(a);
		if (a->next != a && a->data > a->next->data)
			ft_putstr_fd(utils.p[SA](&a, &b), 1);
		else if (a->next != a && a->next->data > d)
			ft_putstr_fd(utils.p[RRA](&a, &b), 1);
		else if (a->next != a && a->data > d)
			ft_putstr_fd(utils.p[RA](&a, &b), 1);
		else if (check_a(a) && !b->is_empty)
			ft_putstr_fd(utils.p[PA](&a, &b), 1);
		else if (!a->is_empty)
			ft_putstr_fd(utils.p[PB](&a, &b), 1);
		else if (!check_b(b) && for_b(a, b, utils))
			;
	}
	return (a);
}

void	get_elm_to_top(t_node **a, t_node **b, t_utils utils, int elm)
{
	int	i;
	int	mid;

	if (!utils.is_b)
		mid = stack_len(*a) / 2;
	else
		mid = stack_len(*b) / 2;
	i = assing_i(*a, *b, utils, elm);
	while (i != 0)
	{
		if (i == 1)
			ft_putstr_fd(utils.p[SA + utils.is_b](a, b), 1);
		else if (i <= mid)
			ft_putstr_fd(utils.p[RA + utils.is_b](a, b), 1);
		else if (i > mid)
			ft_putstr_fd(utils.p[RRA + utils.is_b](a, b), 1);
		i = assing_i(*a, *b, utils, elm);
	}
	ft_putstr_fd(utils.p[PB + utils.is_b](a, b), 1);
}

void	sort(t_node *a, t_node *b, t_utils utils)
{
	int	j;
	int	elm;
	int	c;

	if (check(a, b))
		return ;
	assign_for_norm(&j, &utils, 0, 0);
	while (!a->is_empty)
	{
		c = 0;
		while (c < utils.chunk_size && j < utils.len)
			utils.chunk[c++] = utils.arr[j++];
		while (keep_looping(a, utils.chunk, utils) && !a->is_empty)
		{
			elm = get_elm(a, utils.chunk, utils);
			get_elm_to_top(&a, &b, utils, elm);
		}
	}
	assign_for_norm(&j, &utils, utils.len - 1, 1);
	while (!b->is_empty)
	{
		elm = utils.arr[j--];
		get_elm_to_top(&a, &b, utils, elm);
	}
}
