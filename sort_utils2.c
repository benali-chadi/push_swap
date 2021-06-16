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
	return (i);
}
