#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

typedef struct s_node
{
	int	data;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

void	print_stack(t_node *main)
 {
	t_node *tmp;
	
	printf("%d\n", main->data);
	tmp = main->next;
	while (tmp != main)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	add_last(t_node **main, t_node *new)
{
	t_node *tmp;

	if (!(*main)->next)
	{
		(*main)->next = new;
		(*main)->prev = new;
		new->prev = *main;
		new->next = *main;
		return ;
	}
	tmp = (*main)->next;
	while (tmp->next != *main)
		tmp = tmp->next;
	
	tmp->next = new;
	new->prev = tmp;
	new->next = *main;
}

int main(int ac, char **av)
{
	int i;
	t_node *main;

	if (ac > 1)
	{
		i = 2;
		main = malloc(sizeof(t_node));
		main->data = atoi(av[1]);
		main->next = NULL;
		main->prev = NULL;
		while (av[i])
		{
			t_node *new = malloc(sizeof(t_node));
			new->data = atoi(av[i]);
			add_last(&main, new);
			i++;
		}
		print_stack(main);
	}
	return (0);
}
