#include "get_next_line.h"

int	line_null(char **line)
{
	(*line) = malloc(sizeof(char) * 1);
	if (!(*line))
		return (0);
	(*line)[0] = 0;
	return (1);
}

ssize_t	free_temp(char **temp, ssize_t read_return)
{
	if (*temp)
		free(*temp);
	(*temp) = NULL;
	return (read_return);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	t_index	index;

	if (!s1)
		tab = ft_strdup(s2);
	if (s2[0] == '\0')
		return (malloc(sizeof(char) * 1));
	if (s1 && s2)
	{
		tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!(tab))
			return (NULL);
		index.x = -1;
		while (s1[++index.x])
			tab[index.x] = s1[index.x];
		index.y = 0;
		while (s2[index.y])
			tab[index.x++] = s2[index.y++];
		tab[index.x] = '\0';
	}
	if (s1)
		free(s1);
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
