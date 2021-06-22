#include "../push_swap.h"

// for input reading from args: utils and utils2
// for operations: operation/*.c
char	*ft_stock(char *line, char *buff, int i)
{
	char	*newline;
	int		len;
	int		j;

	j = 0;
	len = 0;
	if (line)
		len = ft_strlen(line);
	if (!(newline = (char *)malloc(len + i + 1)))
		return (0);
	while (j < len)
	{
		newline[j] = line[j];
		j++;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	while (j < len + i)
	{
		newline[j] = buff[j - len];
		j++;
	}
	newline[j] = '\0';
	return (newline);
}

char	*read_in()
{
	char	*ret;
	char	*buf;
	int		i;

	ret = NULL;
	buf = malloc(4);
	if (!buf)
		return (NULL);
	while ((i = read(0, buf, 3)))
	{
		buf[i] = '\0';
		ret = ft_stock(ret, buf, i);
	}
	free(buf);
	return (ret);
}

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
	int i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(ops[i], ins, 3))
			return (i);
		i++;
	}
	return (i);
}

void	exec_insts(t_node **a, t_node **b, t_utils utils, char **split)
{
	int	i;
	int inst;

	i = 0;
	while (split[i])
	{
		inst = check_inst(utils.ops, split[i]);
		if (inst > 10)
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
		utils.p[inst](a, b);
		i++;
	}
}

int main(int ac, char **av)
{
	t_node *a;
	t_node *b;
	t_utils utils;
	char    **split;

	init_p(utils.p);
	init_stack_b(&b);
	init_ops(utils.ops);
	if (ac > 1)
	{
		init_main(&a, av);
		split = ft_split(read_in(), '\n');
		if (split)
			exec_insts(&a, &b, utils, split);
		if (check(a, b))
			ft_putstr_fd("ok\n", 1);
		else
			ft_putstr_fd("ko\n", 1);
	}
	return (0);
}
