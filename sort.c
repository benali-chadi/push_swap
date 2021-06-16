#include "push_swap.h"

int		get_last_data(t_node *main)
{
	t_node	*tmp;
	int		d;

	if (!main->next)
		return (main->data);

	d = main->next->data;
	tmp = main->next;
	while (tmp != main)
	{
		tmp = tmp->next;
		d = tmp->data;
	}
	return (d);
}

int		stack_len(t_node *main)
{
	int i;
	t_node *tmp;

	i = 0;
	if (main->is_empty)
		return (i);
	tmp = main->next;
	i++;
	while (tmp && tmp != main)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*sort_three_nums(t_node *a, t_node *b, t_utils utils)
{
	int i;

	i = 0;
	utils.operations[i] = -1;
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
	while (!check(a, b))
	{
		if (a->data > get_last_data(a))
		{
			utils.p[RA](&a, &b);
			printf("RA\n");
		}
		else if (a->next != a && a->next->data > a->next->next->data)
		{
			utils.p[RRA](&a, &b);
			printf("RRA\n");
		}
		else if (a->next != a && a->data > a->next->data)
		{
			utils.p[SA](&a, &b);
			printf("SA\n");
		}
		else if (check_a(a) && !b->is_empty)
		{
			utils.p[PA](&a, &b);
			printf("PA\n");
		}
		else if (!check_b(b))
		{
			if (b->data < get_last_data(b))
			{
				utils.p[RB](&a, &b);
				printf("RB\n");
			}
			else if (b->next->data < b->next->next->data)
			{
				utils.p[RRB](&a, &b);
				printf("RRB\n");
			}
			else if (b->data < b->next->data)
			{
				utils.p[SB](&a, &b);
				printf("SB\n");
			}
		}

		else if (!a->is_empty)
		{
			utils.p[PB](&a, &b);
			printf("PB\n");
		}
	}
	return (a);
}

int	get_index(t_node *a, int elm)
{
	t_node *tmp;
	int i;

	i = 0;
	if (elm == a->data)
		return (i);
	tmp = a->next;
	i++;
	while (tmp != a)
	{
		if (elm == tmp->data)
			return (i);
		tmp = tmp->next;
		i++;
	}
}

// get a chunk of CHUNK_SIZE
// choose the number with least moves to move to stack b (from the top and the bottom nad compare who's the closest)
// repeat this until the chunk is empty

void	sort(t_node *a, t_node *b, t_utils utils)
{
	// push elements to stack b
	int chunk[utils.chunk_size];
	int count = 0;
	int j = 0;
	while (!a->is_empty)
	{
		// give chunk_size numbers to the chunk
		int c = 0;
		while (c < utils.chunk_size && j < utils.len)
			chunk[c++] = utils.arr[j++];

		// loop while the numbers in the chunk are still in the stack
		while (keep_looping(a, chunk, utils) && !a->is_empty)
		{
			// choos the closest element
			int elm = get_elm(a, chunk, utils);
			// get len/2 of a
			int mid = stack_len(a) / 2;
			int i = get_index(a, elm); // = the index of the a->data = elm
			printf("elm=%d\n", elm);
			while (i != 0)
			{
				if (i == 1)
				{
					utils.p[SA](&a, &b);
					printf("SA\n");
				}
				else if (i <= mid)
				{

					utils.p[RA](&a, &b);
					printf("RA\n");
				}
				else if (i > mid)
				{
					utils.p[RRA](&a, &b);
					printf("RRA\n");
				}
				i = get_index(a, elm); // the index of the a->data = elm
				count++;
			}
			utils.p[PB](&a, &b);
			printf("PB\n");
			count++;
		}
	}
	// push the elements back to stack a
	j = utils.len - 1;
	while (!b->is_empty)
	{
		int elm = utils.arr[j--];
	// get len/2 of a
		int mid = stack_len(b) / 2;
		int i = get_index(b, elm); // = the index of the a->data = elm
		printf("elm=%d\n", elm);
		while (i != 0)
		{
			if (i == 1)
			{
				utils.p[SB](&a, &b);
				printf("SB\n");
			}
			else if (i <= mid)
			{

				utils.p[RB](&a, &b);
				printf("RB\n");
			}
			else if (i > mid)
			{
				utils.p[RRB](&a, &b);
				printf("RRB\n");
			}
			i = get_index(b, elm);
			// printf("len = %d\telm = %d\tmid = %d\ti=%d\n", stack_len(b), elm, mid, i); // the index of the a->data = elm
			count++;
		}
		utils.p[PA](&a, &b);
		printf("PA\n");
		count++;
		// utils.p[PA](&a, &b);
		// printf("PA\n");
		// count++;
	}
	printf("a:\n");
	print_stack(a);
	printf("count = %d\n", count);
}