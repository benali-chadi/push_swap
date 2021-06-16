#include "push_swap.h"

t_node	*sort_three_nums(t_node *a, t_node *b, t_utils utils)
{
	int i;

	i = 0;
	while (!check_a(a))
	{
		if (a->data > a->next->next->data)
		{
			utils.p[RA](&a, &b);
			printf("RA\n");
		}
		else if (a->next->data > a->next->next->data)
		{
			utils.p[RRA](&a, &b);
			printf("RRA\n");
		}
		else if (a->data > a->next->data)
		{
			utils.p[SA](&a, &b);
			printf("SA\n");
		}
	}
	printf("a:\n");
	print_stack(a);
	printf("b:\n");
	print_stack(b);
	return (a);
}

t_node	*sort_few_nums(t_node *a, t_node *b, t_utils utils)
{
	int i = 0;
	while (!check(a, b))
	{
		if (a->data > get_last_data(a))
			ft_putstr_fd(utils.p[RA](&a, &b), 1);
		else if (a->next != a && a->next->data > a->next->next->data)
			ft_putstr_fd(utils.p[RRA](&a, &b), 1);
		else if (a->next != a && a->data > a->next->data)
			ft_putstr_fd(utils.p[SA](&a, &b), 1);
		else if (check_a(a) && !b->is_empty)
			ft_putstr_fd(utils.p[PA](&a, &b), 1);
		else if (!check_b(b))
		{
			if (b->data < get_last_data(b))
				ft_putstr_fd(utils.p[RB](&a, &b), 1);
			else if (b->next->data < b->next->next->data)
				ft_putstr_fd(utils.p[RRB](&a, &b), 1);
			else if (b->data < b->next->data)
				ft_putstr_fd(utils.p[SB](&a, &b), 1);
		}
		else if (!a->is_empty)
			ft_putstr_fd(utils.p[PB](&a, &b), 1);
		i++;
	}
	printf("i=%d\n", i);
	return (a);
}

// get a chunk of CHUNK_SIZE
// choose the number with least moves to move to stack b (from the top and the bottom nad compare who's the closest)
// repeat this until the chunk is empty

void	get_elm_to_top(t_node *a, t_node *b, t_utils utils, int elm, int *count)
{
	int i;
	int mid;

	if (!utils.is_b)
	{
		mid = stack_len(a) / 2;
		i = get_index(a, elm);
	}
	else
	{
		mid = stack_len(b) / 2;
		i = get_index(b, elm);
	}
	while (i != 0)
	{
		if (i == 1)
			ft_putstr_fd(utils.p[SA + utils.is_b](&a, &b), 1);
		else if (i <= mid)
			ft_putstr_fd(utils.p[RA + utils.is_b](&a, &b), 1);
		else if (i > mid)
			ft_putstr_fd(utils.p[RRA + utils.is_b](&a, &b), 1);
		if (!utils.is_b)
			i = get_index(a, elm);
		else
			i = get_index(b, elm);
		(*count)++;
	}
	ft_putstr_fd(utils.p[PB + utils.is_b](&a, &b), 1);
	(*count)++;
}

void	sort(t_node *a, t_node *b, t_utils utils)
{
	int chunk[utils.chunk_size];
	int count = 0;
	int j;
	int elm;
	int c;

	j = 0;
	utils.is_b = 0;
	while (!a->is_empty)
	{
		c = 0;
		while (c < utils.chunk_size && j < utils.len)
			chunk[c++] = utils.arr[j++];
		while (keep_looping(a, chunk, utils) && !a->is_empty)
		{
			elm = get_elm(a, chunk, utils);
			get_elm_to_top(a, b, utils, elm, &count);
		}
	}
	j = utils.len - 1;
	utils.is_b = 1;
	while (!b->is_empty)
	{
		elm = utils.arr[j--];
		get_elm_to_top(a, b, utils, elm, &count);
	}
	printf("a:\n");
	print_stack(a);
	printf("count = %d\n", count);
}
