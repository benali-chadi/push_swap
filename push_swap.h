#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

# define SA 0
# define RA 1
# define RRA 2
# define PB 3
# define PA 4
# define SB 5
# define RB 6
# define RRB 7
# define SS 8
# define RR 9
# define RRR 10

typedef struct s_node
{
	int	data;
	int is_empty;
	struct s_node *next;
	struct s_node *prev;
}				t_node;

typedef struct	s_utils
{
	void	(*p[12]) (t_node **a, t_node **b);
	char	*ops[11];
	int		operations[1000];
	int		num;
}				t_utils;

void	add_last(t_node **main, t_node *new);
int		check(t_node *main, t_node *b);
int		check_a(t_node *main);
int		sort(t_node *a, t_node *b, t_utils utils, int val, int i);
void	print_stack(t_node *main);

t_node	*sort_three_nums(t_node *a, t_node *b, t_utils utils);
void	sort_five_nums(t_node *a, t_node *b, t_utils utils);

int		stack_len(t_node *main);

/*
	** Operations
*/

void	ft_swap(t_node **main);
void	swap_a(t_node **a, t_node **b);
void	swap_b(t_node **a, t_node **b);
void	swap_s(t_node **a, t_node **b);

void	ft_push(t_node **a, t_node **b);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **a, t_node **b);

void	ft_rotate(t_node **main);
void	rotate_a(t_node **a, t_node **b);
void	rotate_b(t_node **a, t_node **b);
void	rotate_s(t_node **a, t_node **b);

void	ft_reverse(t_node **main);
void	reverse_a(t_node **a, t_node **b);
void	reverse_b(t_node **a, t_node **b);
void	reverse_s(t_node **a, t_node **b);


#endif