#include "push_swap.h"

static void	for_norme(t_node *main, t_utils *utils)
{
	init_p(utils->p);
	utils->arr = sort_array(main, stack_len(main), utils);
	utils->len = stack_len(main);
	utils->i = 0;
}

int	main(int ac, char **av)
{
	t_node	*main;
	t_node	*main_b;
	t_utils	utils;

	init_stack_b(&main_b, &utils);
	if (ac > 1)
	{
		init_main(&main, av, &utils);
		for_norme(main, &utils);
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
		sort(main, main_b, &utils);
		to_free(&utils);
	}
	return (0);
}
