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
	char	**file;
	int		file_y;

	fd = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "\nInvalid file .cub\n", 19);
		return (0);
	}
	file = NULL;
	file_y = 1;
	file = read_parsing(cub, fd, line, &file_y);
	if (!file)
		return (0);
	close(fd);
	if (!(ft_map(cub, file, file_y - 1)))
		return (0);
	// if (!(get_textures(cub)))
	// 	return (0);
	// printf("Rx:		%d && Ry :%d\n", cub->parsing.rx, cub->parsing.ry);
	// printf("NO:		%s\n", cub->parsing.no);
	// printf("SO:		%s\n", cub->parsing.so);
	// printf("EA:		%s\n", cub->parsing.ea);
	// printf("WE:		%s\n", cub->parsing.we);
	// printf("S:		%s\n", cub->parsing.s);
	// printf("Fx:		%f && Fy :%f && Fz :%f\n", cub->parsing.f.x, cub->parsing.f.y, cub->parsing.f.z);
	// printf("Cx:		%f && Cy :%f && Cz :%f\n\n", cub->parsing.c.x, cub->parsing.c.y, cub->parsing.c.z);
	// printf("	---------------------\n\n");
	// for (int i = 0;i < cub->parsing.map_y;i++)
	// 	printf("	%s\n", cub->parsing.world_map[i]);
	// printf("\n	---------------------\n\n");
	// printf("Cardinal:	%c\n", cub->parsing.cardinal);
	// printf("Px:		%d\n", cub->parsing.px);
	// printf("Py:		%d\n", cub->parsing.py);
	return (1);
}