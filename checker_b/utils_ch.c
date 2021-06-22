#include "../push_swap.h"

char	*read_in()
{
	char	*ret;
	char	*buf;
	int		i;

	ret = NULL;
	buf = malloc(4);
	if (!buf)
		return (NULL);
	while ((i = read(0, buf, 3)))
	{
		buf[i] = '\0';
		ret = ft_stock(ret, buf, i);
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
	if (!(newline = (char *)malloc(len + i + 1)))
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
