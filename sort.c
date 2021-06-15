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

void	sort_five_nums(t_node *a, t_node *b, t_utils utils)
{
	int i;

	i = 0;
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
		// else if (!check_b(b))
		// {
		// 	if (b->data < get_last_data(b))
		// 	{
		// 		utils.p[RB](&a, &b);
		// 		printf("RB\n");
		// 	}
		// 	else if (b->next->data < b->next->next->data)
		// 	{
		// 		utils.p[RRB](&a, &b);
		// 		printf("RRB\n");
		// 	}
		// 	else if (b->data < b->next->data)
		// 	{
		// 		utils.p[SB](&a, &b);
		// 		printf("SB\n");
		// 	}
		// 	// else if (check_a(b))
		// 	// {
		// 	// 	utils.p[PB](&a, &b);
		// 	// 	printf("PB\n");
		// 	// }
		// }
		else if (!a->is_empty)
		{
			utils.p[PB](&a, &b);
			printf("PB\n");
		}
		i++;
	}
	printf("i=%d\n", i);
	printf("a:\n");
	print_stack(a);
	printf("b:\n");
	print_stack(b);
}

int	get_smlst_elm(t_node *a, int elm)
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

void	sort(t_node *a, t_node *b, t_utils utils)
{
	// while (check(a, b))
	// {
	// 	// choose the smallest not sorted five elements in the stack a
	// 	// push the five elements to stack b
	// 	while (check_b(b))
	// 	{
	// 		// sort the elements
	// 	}
	// 	// push the elements back to stack a
	// }

	// push elements to stack b
	int count = 0;
	int j = 0;
	while (!a->is_empty)
	{
		// get elm from the sorted array
		int elm = utils.arr[j++];
		// get len/2 of a
		int mid = stack_len(a) / 2;
		int i = get_smlst_elm(a, elm); // = the index of the a->data = elm
		printf("elm=%d\n", elm);
		while (i != 0)
		{
			if (i == 1)
			{
				utils.p[SA](&a, &b);
				printf("SA\n");
			}
			else if (i < mid)
			{

				utils.p[RA](&a, &b);
				printf("RA\n");
			}
			else if (i >= mid)
			{
				utils.p[RRA](&a, &b);
				printf("RRA\n");
			}
			i = get_smlst_elm(a, elm);// the index of the a->data = elm
			count++;
		}
		utils.p[PB](&a, &b);
		printf("PB\n");
		count++;
	}
	// push the elements back to stack a
	while (!b->is_empty)
	{
		utils.p[PA](&a, &b);
		printf("PA\n");
		count++;
	}
	printf("count = %d\n", count);
	printf("a:\n");
	print_stack(a);
	printf("b:\n");
	print_stack(b);
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