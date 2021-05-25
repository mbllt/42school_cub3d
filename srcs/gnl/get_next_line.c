#include "get_next_line.h"

int	reset_temp(char **temp, int read_return)
{
	int		i;
	int		a;
	char	*str;

	str = ft_strdup(*temp);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (*temp)
		free(*temp);
	(*temp) = malloc(sizeof(char) * (read_return - i + 1));
	if (!(*temp))
		return (-1);
	a = 0;
	i++;
	while (i < read_return)
		(*temp)[a++] = str[i++];
	(*temp)[a] = '\0';
	if (str)
		free(str);
	return (1);
}

int	fill_in_line(char **temp, ssize_t read_return, char **line)
{
	int	i;
	int	a;

	if ((*line))
		free(*line);
	if (read_return == 0)
	{
		(*line) = ft_strdup(*temp);
		return (1);
	}
	i = 0;
	while ((*temp)[i] != '\0' && (*temp)[i] != '\n')
		i++;
	(*line) = malloc(sizeof(char) * i + 1);
	if (!(*line))
		return (0);
	a = 0;
	while (a < i)
	{
		(*line)[a] = (*temp)[a];
		a++;
	}
	(*line)[a] = '\0';
	return (1);
}

int	fill_in_temp(char **temp, char *buffer, ssize_t read_return)
{
	buffer[read_return] = '\0';
	(*temp) = ft_strjoin(*temp, buffer);
	if (!(*temp))
	{
		free(*temp);
		return (0);
	}
	return (1);
}

int	condition_fill_in_temp(char **temp)
{
	int	i;

	i = 0;
	if (*temp)
	{
		while ((*temp)[i] && (*temp)[i] != '\n')
			i++;
		if ((*temp)[i] == '\n')
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*temp[4096];
	ssize_t			read_return;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (!(line_null(line)))
		return (-1);
	read_return = 1;
	if (temp[fd])
		read_return = ft_strlen(temp[fd]);
	while (!(condition_fill_in_temp(&temp[fd])))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		if (!(fill_in_temp(&temp[fd], buffer, read_return)))
			return (-1);
	}
	if (temp[fd] && (!(fill_in_line(&temp[fd], read_return, line)) \
		|| !(reset_temp(&temp[fd], ft_strlen(temp[fd])))))
		return (-1);
	if (read_return == 0)
		return ((free_temp(&temp[fd], read_return)));
	return (1);
}
