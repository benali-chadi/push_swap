#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

// For 100 nums chunk_size 10
// For 500 nums chunk_size 40

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

// # define utils.chunk_size 40

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
	int		len;
	int		*arr;
	int		chunk_size;
}				t_utils;

void	add_last(t_node **main, t_node *new);


/*
	** Sort
*/

void	sort(t_node *a, t_node *b, t_utils utils);
t_node	*sort_three_nums(t_node *a, t_node *b, t_utils utils);
t_node	*sort_few_nums(t_node *a, t_node *b, t_utils utils);
int		*sort_array(t_node *a, int len);

int     get_elm(t_node *a, int *chunk, t_utils utils);
int		keep_looping(t_node *a, int *chunk, t_utils utils);

/*
	** Utils
*/

void	print_stack(t_node *main);
int		check(t_node *main, t_node *b);
int		check_a(t_node *main);
int		check_b(t_node *main);
void	init_p(void (*p[12])(t_node **a, t_node **b));
void	init_ops(char *ops[11]);
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