#include "../push_swap.h"

char	*read_in(void)
{
	char	*ret;
	char	*buf;
	int		i;

	ret = NULL;
	buf = malloc(4);
	if (!buf)
		return (NULL);
	i = read(0, buf, 3);
	while (i)
	{
		buf[i] = '\0';
		ret = ft_stock(ret, buf, i);
		i = read(0, buf, 3);
	}
	free(buf);
	return (ret);
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
