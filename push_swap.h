#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_node
{
	int	data;
	int is_empty;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

void	add_last(t_node **main, t_node *new);

// Tools
void	ft_swap(t_node **main, t_node **b);
void	ft_push(t_node **a, t_node **b);
void	ft_rotate(t_node **main, t_node **b);
void	ft_reverse(t_node **main, t_node **b);

#endif