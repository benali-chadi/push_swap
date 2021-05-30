#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_node
{
	int	data;
	int is_empty;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

void	add_last(t_node **main, t_node *new);

/*
	** Operations
*/

void	ft_swap(t_node **main);
void    swap_a(t_node **a, t_node **b);
void    swap_b(t_node **a, t_node **b);
void    swap_s(t_node **a, t_node **b);

void	ft_push(t_node **a, t_node **b);
void    push_a(t_node **a, t_node **b);
void    push_b(t_node **a, t_node **b);

void	ft_rotate(t_node **main);
void    rotate_a(t_node **a, t_node **b);
void    rotate_b(t_node **a, t_node **b);
void    rotate_s(t_node **a, t_node **b);

void	ft_reverse(t_node **main);
void    reverse_a(t_node **a, t_node **b);
void    reverse_b(t_node **a, t_node **b);
void    reverse_s(t_node **a, t_node **b);


#endif