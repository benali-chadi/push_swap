#include "push_swap.h"

int	sort(t_node *a, t_node *b, t_utils utils, int val, int i)
{
	if (i > 10)
		return (0);
	if (check(a, b))
	{
		int j = 0;
		printf("operations\n");
		while (utils.operations[j] >= 0)
		{
			printf("%s\n", utils.ops[utils.operations[j++]]);
		}
		
		printf("a:\n");
		print_stack(a);
		printf("b:\n");
		print_stack(b);
		exit(0);
		// return (0);
	}
	// printf("ok\n");

	// while (!a->is_empty && i < 10)
	// while (!check(a, b))
	// {
		printf("i=%d\n", i);
		utils.p[val](&a, &b);
		utils.operations[i] = val;
		utils.operations[++i] = -1;
		if (sort(a, b, utils, rand() % 11, i) || 
		sort(a, b, utils, rand() % 11, i) || 
		sort(a, b, utils, rand() % 11, i) || 
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i) ||
		sort(a, b, utils, rand() % 11, i)
		);
			// break;
			// return (1);
		// utils.operations[i] = -1;
	// }
	// return (0);
}
