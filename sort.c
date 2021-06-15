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

t_node	*sort_five_nums(t_node *a, t_node *b, t_utils utils, int *i)
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
		else if (!a->is_empty)
		{
			utils.p[PB](&a, &b);
			printf("PB\n");
		}
		(*i)++;
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

// get a chunk of 5
// choose the number with least moves to move to stack b (from the top and the bottom nad compare who's the closest)
// repeat this until the chunk is empty

int		compare(int chunk[CHUNK_LEN], int data)
{
	int i;

	i = 0;
	while (i < CHUNK_LEN)
	{
		if (chunk[i++] == data)
			return (1);
	}
	return (0);
}

int		keep_looping(t_node *a, int chunk[CHUNK_LEN])
{
	t_node *tmp;

	if (compare(chunk, a->data))
		return (1);
	tmp = a->next;
	while (tmp != a)
	{
		if (compare(chunk, tmp->data))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		get_elm(t_node *a, int chunk[CHUNK_LEN])
{
	t_node	*tmp;
	int		elm1;
	int		elm2;
	int		i;
	int		j;

	if (compare(chunk, a->data))
		return (a->data);
	tmp = a->next;
	i = 1;
	while (tmp != a)
	{
		if (compare(chunk, tmp->data))
		{
			elm1 = tmp->data;
			break;
		}
		i++;
		tmp = tmp->next;
	}
	tmp = a->prev;
	j = 1;
	while (tmp != a)
	{
		if (compare(chunk, tmp->data))
		{
			elm2 = tmp->data;
			break;
		}
		j++;
		tmp = tmp->prev;
	}
	if (i <= j)
		return (elm1);
	else
		return (elm2);
}

void	sort(t_node *a, t_node *b, t_utils utils)
{
	// push elements to stack b
<<<<<<< HEAD
	t_node *tmp;
	tmp = malloc(sizeof(t_node));
	tmp->data = 0;
	tmp->next = tmp;
	tmp->prev = tmp;
	tmp->is_empty = 1;
	int count = 0;
	int j = 0;
	int len = stack_len(a);
	int chunk[10];
	while (stack_len(a) > 5)//!a->is_empty)
	{
		// get elm from the sorted array
		int end = j + 10;
		for (int c = 0; c < end; c++)
			chunk[c] = utils.arr[j++];
		int elm = utils.arr[j++];
		// get len/2 of a
		int mid = stack_len(a) / 2;
		int i = get_smlst_elm(a, elm); // = the index of the a->data = elm
=======
	int chunk[CHUNK_LEN];
	int count = 0;
	int j = 0;
	while (!a->is_empty)
	{
		// get elm from the sorted array
		// int elm = utils.arr[j++];

		// give five numbers to the chunk
		int c = 0;
		while (c < CHUNK_LEN && j < utils.len)
			chunk[c++] = utils.arr[j++];

		// loop while the numbers in the chunk are still in the stack
		while (keep_looping(a, chunk) && !a->is_empty)
		{
			// choos the closest element
			int elm = get_elm(a, chunk);
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
	// a = sort_five_nums(a, b, utils, &count);
	// printf("count = %d\n", count);
	// count = 0;

	// push the elements back to stack a
	j = utils.len - 1;
	while (!b->is_empty)
	{
		int elm = utils.arr[j--];
	// get len/2 of a
		int mid = stack_len(b) / 2;
		int i = get_index(b, elm); // = the index of the a->data = elm
>>>>>>> 86d445582ab0a326ba32c5d08914094cdda5aec0
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
			printf("len = %d\telm = %d\tmid = %d\ti=%d\n", stack_len(b), elm, mid, i); // the index of the a->data = elm
			count++;
		}
<<<<<<< HEAD
		utils.p[PB](&a, &b);
		printf("PB\n");
		count++;
	}
	a = sort_five_nums(a, tmp, utils, &count);
	printf("count = %d\n", count);
	count = 0;
	// push the elements back to stack a
	while (!b->is_empty)
	{
=======
>>>>>>> 86d445582ab0a326ba32c5d08914094cdda5aec0
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

int	*sort_array(t_node *a, int len)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		*arr;
	int		key;

	len = stack_len(a);
	i = 0;
	arr = malloc(len * sizeof(int));
	arr[i] = a->data;
	tmp = a->next;
	i++;
	// fill the arr
	while (tmp != a)
	{
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}

	// sort the arr from smallest to biggest
	i = 1;
	while (i < len)
	{
		j = i - 1;
		key = arr[i];
		while (key < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		i++;
	}
	// i = 0;
	// while (i < len)
	// 	printf("%d ", arr[i++]);
	// printf("\n");
	return (arr);
}