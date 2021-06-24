#include "../push_swap.h"

void	init_ops(char *ops[11])
{
	ops[0] = "sa";
	ops[1] = "sb";
	ops[2] = "ra";
	ops[3] = "rb";
	ops[4] = "rra";
	ops[5] = "rrb";
	ops[6] = "pb";
	ops[7] = "pa";
	ops[8] = "ss";
	ops[9] = "rr";
	ops[10] = "rrr";
}

int	check_inst(char *ops[11], char *ins)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(ops[i], ins, 3))
			return (i);
		i++;
	}
	return (i);
}

void	exec_insts(t_node **a, t_node **b, t_utils utils, char *buf)
{
	int	inst;

	inst = check_inst(utils.ops, buf);
	if (inst > 10)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	utils.p[inst](a, b);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_utils		utils;

	init_p(utils.p);
	init_stack_b(&b);
	init_ops(utils.ops);
	if (ac > 1)
	{
		init_main(&a, av);
		read_in(&a, &b, utils);
		if (check(a, b))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (0);
}
