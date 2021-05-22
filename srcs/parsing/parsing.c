#include "cub3D.h"

static int	ft_cpy(char **file, char *line, int size, int j)
{
	int	i;

	file[j] = malloc(sizeof(char) * size + 1);
	if (!file)
		return (0);
	i = 0;
	while (i < size)
	{
		file[j][i] = line[i];
		i++;
	}
	file[j][i] = 0;
	return (1);
}

static char	**ft_realloc_double(char **str, int size_src, int size_dst)
{
	char	**temp;
	int		i;

	if (!(*str))
		return (NULL);
	if (!(temp = malloc(sizeof(char*) * size_dst)))
	{
		if (str)
			free(str);
		return (NULL);
	}
	i = 0;
	while (i < size_src)
	{
		temp[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (temp);
}

static char	**read_parsing(t_vars *cub, int fd, char *line, int *file_y)
{
	int	ret;
	char **file;

	ret = 1;
	file = NULL;
	while (ret > 0)
	{
		if (line)
			free(line);
		ret = get_next_line(fd, &line);
		if (ret >= 0 && !(check_data(cub, line, ret)))
			ret = -1;
		if ((*file_y) == 1)
			file = malloc(sizeof(char *) * (*file_y));
		else
			file = ft_realloc_double(file, ((*file_y) - 1), (*file_y));
		if (!file)
			return (NULL);
		ft_cpy(file, line, ft_strlen(line), (*file_y) - 1);
		if (!file)
			return (NULL);
		(*file_y)++;
	}
	if (line)
		free(line);
	if (ret == -1)
		return (NULL);
	return (file);
}

int	parsing(t_vars *cub, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "\nInvalid file .cub\n", 19);
		return (0);
	}
	cub->parsing.file = NULL;
	cub->parsing.file_y = 1;
	cub->parsing.file = read_parsing(cub, fd, line, &cub->parsing.file_y);
	if (!cub->parsing.file)
		return (0);
	close(fd);
	if (!(ft_map(cub, cub->parsing.file, cub->parsing.file_y - 1)))
		return (0);
	return (1);
}