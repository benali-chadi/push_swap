#include "push_swap.h"

int	check_b(t_node *main)
{
	int		d;
	t_node	*tmp;

	if (main->next == main || main->is_empty)
		return (1);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data > d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

int	check_a(t_node *main)
{
	int		d;
	t_node	*tmp;

	if (main->next == main || main->is_empty)
		return (0);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data < d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

int	check(t_node *main, t_node *b)
{
	int		d;
	t_node	*tmp;

	if (!b->is_empty)
		return (0);
	d = main->data;
	tmp = main->next;
	while (tmp != main)
	{
		if (tmp->data < d)
			return (0);
		d = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}

void	init_p(char *(*p[12])(t_node **a, t_node **b, t_utils *utils))
{
	p[0] = swap_a;
	p[1] = swap_b;
	p[2] = rotate_a;
	p[3] = rotate_b;
	p[4] = reverse_a;
	p[5] = reverse_b;
	p[6] = push_b;
	p[7] = push_a;
	p[8] = swap_s;
	p[9] = rotate_s;
	p[10] = reverse_s;
	p[11] = NULL;
}

void	error_and_exit(char *av, long long data)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	if (!av)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	while (av[++i])
		if ((av[i] < '0' || av[i] > '9') && av[i] != '-')
			f = 1;
	if (data > 2147483647 || data < -2147483648 || f)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}
