
#include "cub3D.h"

int	is_cardinal(char c)
{
	if (c == 'N')
		return (0);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (2);
	if (c == 'W')
		return (3);
	if (c == 'F')
		return (4);
	if (c == 'C')
		return (5);
	if (c == 'S')
		return (6);
	return (-1);
}

int	check_if_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static size_t	find_size(char *s, int start)
{
	size_t	size;

	if ((size_t)start < ft_strlen(s))
		size = ft_strlen(s + start);
	else
		size = 0;
	return (size);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = find_size(s, start);
	if (size > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (size == 0 || len == 0)
	{
		str[i] = '\0';
		return (str);
	}
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	if (!src || !dest)
		return (0);
	j = ft_strlen(src);
	if (destsize == 0)
		return (j);
	i = 0;
	while (src[i] && i + 1 < destsize)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}