#include "cub3D.h"

static size_t	nbr_str(const char *s, char c)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	if (s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c && i - 1 >= 0 && s[i - 1] != c)
		{
			//printf("%c\n", s[i]);
			size++;
		}
		i++;
	}
	if (s[i - 1] != c)
	{
		size++;
	}
	return (size);
}

static int		find_start(const char *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] == c)
		i++;
	return (i);
}

static int		find_len(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		start++;
		len++;
	}
	return (len);
}

int	free_malloc(char **dest, int i)
{
	while (i >= 0)
		free(dest[i--]);
	free(dest);
	return (1);
}

char	**ft_split(char *s, char c, int *size)
{
	int		start;
	int		len;
	char	**dest;
	int		i;

	if (!s)
		return (NULL);
	(*size) = nbr_str(s, c);
	dest = (char **)malloc(sizeof(char *) * (*size) + sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	start = 0;
	len = 0;
	while (++i < (*size))
	{
		start = find_start(s, c, start + len);
		len = find_len(s, c, start);
		dest[i] = ft_substr(s, start, len);
		if (!(dest[i]))
			if (free_malloc(dest, i - 1))
				return (NULL);
	}
	dest[i] = NULL;
	return (dest);
}