#include "push_swap.h"

void	print_stack(t_node *main)
{
	t_node	*tmp;

	if (main->is_empty)
	{
		printf("empty\n");
		return ;
	}
	printf("%lld\n", main->data);
	tmp = main->next;
	while (tmp && tmp != main)
	{
		printf("%lld\n", tmp->data);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*main;
	t_node	*main_b;
	t_utils	utils;

	init_p(utils.p);
	init_stack_b(&main_b);
	if (ac > 1)
	{
		init_main(&main, av);
		utils.arr = sort_array(main, stack_len(main));
		utils.len = stack_len(main);
		if (utils.len <= 10)
		{
			utils.chunk_size = 0;
			sort_few_nums(main, main_b, utils);
			return (0);
		}
		else if (utils.len <= 100)
			utils.chunk_size = 10;
		else
			utils.chunk_size = 40;
		sort(main, main_b, utils);
	}
	return (0);
}
