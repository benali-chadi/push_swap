#include "../push_swap.h"

int	stop(char *buf)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

void	read_in(t_node **a, t_node **b, t_utils utils)
{
	char	*str;
	char	*buf;
	int		i;

	str = NULL;
	buf = malloc(5);
	if (!buf)
		exit(1);
	i = read(0, buf, 3);
	while (i)
	{
		if (i == 1 && !ft_isalpha(buf[1]))
			error_and_exit(NULL, 0);
		else if (i == 1)
			i = read(0, buf, 3);
		buf[i] = '\0';
		buf[stop(buf)] = '\0';
		exec_insts(a, b, utils, buf);
		i = read(0, buf, 3);
	}
	free(buf);
}

char	*ft_stock(char *line, char *buff, int i)
{
	char	*newline;
	int		len;
	int		j;

	j = -1;
	len = 0;
	if (line)
		len = ft_strlen(line);
	newline = (char *)malloc(len + i + 1);
	if (!newline)
		return (0);
	while (++j < len)
		newline[j] = line[j];
	if (line)
	{
		free(line);
		line = NULL;
	}
	j--;
	while (++j < len + i)
		newline[j] = buff[j - len];
	newline[j] = '\0';
	return (newline);
}
