#include "push_swap.h"

void	*m_malloc(size_t n, t_utils *utils)
{
	void		*tmp;

	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	utils->alloc[utils->i] = tmp;
	utils->i++;
	return (tmp);
}

void	to_free(t_utils *utils)
{
	int	i;

	i = -1;
	while (++i < utils->i)
		free(utils->alloc[i]);
}
