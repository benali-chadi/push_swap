#include "push_swap.h"

int		compare(int *chunk, int data, t_utils utils)
{
	int i;

	i = 0;
	while (i < utils.chunk_size)
	{
		if (chunk[i++] == data)
			return (1);
	}
	return (0);
}

int		keep_looping(t_node *a, int *chunk, t_utils utils)
{
	t_node *tmp;

	if (compare(chunk, a->data, utils))
		return (1);
	tmp = a->next;
	while (tmp != a)
	{
		if (compare(chunk, tmp->data, utils))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int     get_element(t_node *a, int next, int *i, int *chunk, t_utils utils)
{
    t_node *tmp;

    if (next)
        tmp = a->next;
    else
        tmp = a->prev;
    while (tmp != a)
    {
        if (compare(chunk, tmp->data, utils))
            return (tmp->data);
        if (next)
            tmp = tmp->next;
        else
            tmp = tmp->prev;
        (*i)++;
    }
	return (0);
}

int     get_elm(t_node *a, int *chunk, t_utils utils)
{
	int		elm1;
	int		elm2;
	int		i;
	int		j;

	if (compare(chunk, a->data, utils))
		return (a->data);
	i = 1;
    elm1 = get_element(a, 1, &i, chunk, utils);
	j = 1;
    elm2 = get_element(a, 0, &j, chunk, utils);
	if (i <= j)
		return (elm1);
	else
		return (elm2);
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
	return (arr);
}