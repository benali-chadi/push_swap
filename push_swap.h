#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

// For 100 nums chunk_size 10
// For 500 nums chunk_size 40

# define SA 0
# define SB 1
# define RA 2
# define RB 3
# define RRA 4
# define RRB 5
# define PB 6
# define PA 7
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
	char	*(*p[12]) (t_node **a, t_node **b);
	int		len;
	int		*arr;
	int		chunk_size;
	int		is_b;
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
int		get_last_data(t_node *main);
int		stack_len(t_node *main);
int		get_index(t_node *a, int elm);
int		assing_i(t_node *a, t_node *b, t_utils utils, int elm);

/*
	** Utils
*/

void	print_stack(t_node *main);
int		check(t_node *main, t_node *b);
int		check_a(t_node *main);
int		check_b(t_node *main);
void	init_p(char *(*p[12])(t_node **a, t_node **b));
int		stack_len(t_node *main);
void	error_and_exit();


/*
	** Operations
*/

void	ft_swap(t_node **main);
char	*swap_a(t_node **a, t_node **b);
char	*swap_b(t_node **a, t_node **b);
char	*swap_s(t_node **a, t_node **b);

void	ft_push(t_node **a, t_node **b);
char	*push_a(t_node **a, t_node **b);
char	*push_b(t_node **a, t_node **b);

void	ft_rotate(t_node **main);
char	*rotate_a(t_node **a, t_node **b);
char	*rotate_b(t_node **a, t_node **b);
char	*rotate_s(t_node **a, t_node **b);

void	ft_reverse(t_node **main);
char	*reverse_a(t_node **a, t_node **b);
char	*reverse_b(t_node **a, t_node **b);
char	*reverse_s(t_node **a, t_node **b);


#endif