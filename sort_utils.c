#include "push_swap.h"

int	compare(int *chunk, int data, t_utils utils)
{
	int	i;

	i = 0;
	while (i < utils.chunk_size)
	{
		if (chunk[i++] == data)
			return (1);
	}
	return (0);
}

int	get_element(t_node *a, int *i, int *chunk, t_utils utils)
{
	t_node	*tmp;

	if (utils.next)
		tmp = a->next;
	else
		tmp = a->prev;
	while (tmp != a)
	{
		if (compare(chunk, tmp->data, utils))
			return (tmp->data);
		if (utils.next)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
		(*i)++;
	}
	return (0);
}

int	get_elm(t_node *a, int *chunk, t_utils utils)
{
	int	elm1;
	int	elm2;
	int	i;
	int	j;

	if (compare(chunk, a->data, utils))
		return (a->data);
	i = 1;
	utils.next = 1;
	elm1 = get_element(a, &i, chunk, utils);
	j = 1;
	utils.next = 0;
	elm2 = get_element(a, &j, chunk, utils);
	if (i <= j)
		return (elm1);
	else
		return (elm2);
}

int	*insertion_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	key;

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
	return (arr);
}

int	*sort_array(t_node *a, int len)
{
	t_node	*tmp;
	int		i;
	int		*arr;

	len = stack_len(a);
	i = 0;
	arr = malloc(len * sizeof(int));
	arr[i] = a->data;
	tmp = a->next;
	i++;
	while (tmp != a)
	{
		arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	return (insertion_sort(arr, len));
}
