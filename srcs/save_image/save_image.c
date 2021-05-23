#include "cub3D.h"

static int	malloc_temp(t_vars *cub, unsigned int ***temp)
{
	int				i;

	(*temp) = malloc(sizeof(unsigned int *) * cub->parsing.rx);
	if ((*temp))
		return (0);
	i = -1;
	while (++i < cub->parsing.rx)
	{
		(*temp)[i] = malloc(sizeof(unsigned int) * cub->parsing.ry);
		if (!(*temp)[i])
		{
			while (--i >= 0)
				if ((*temp)[i])
					free((*temp)[i]);
			free((*temp));
			return (0);
		}
	}
	return (1);
}

static int	fill_in_str(t_vars *cub, unsigned int ***temp)
{
	int				i;
	int				j;

	(*temp) = NULL;
	malloc_temp(cub, temp);
	if (!(*temp))
		return (0);
	i = 0;
	while (i < cub->parsing.rx)
	{
		j = 0;
		while (j < cub->parsing.ry)
		{
			(*temp)[i][j] = cub->pixel_data[i][j];
			//printf("yoy\n");
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_free_temp(unsigned int **temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (temp[i])
			free(temp[i]);
		i++;
	}
	if (temp)
		free(temp);
}

int	save_image(t_vars *cub)
{
	int				fd;
	int				ret_write;
	unsigned int	**temp;

	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 00777); /* try with S_IRWXO */
	if (fd < 0)
	{
		return (0);
	}
	ret_write = write(fd, (char *)&cub->save, sizeof(cub->save));
	if (ret_write < 0)
	{
		return (0);
	}
	fill_in_str(cub, &temp);
	if (!temp)
	{
		return (0);
	}
	ret_write = write(fd, (char *)&temp, (cub->parsing.rx * cub->parsing.ry) * 4);
	if (ret_write < 0)
	{
		return (0);
	}
	close(fd);
	ft_free_temp(temp, cub->parsing.rx);
	return (1);
}

//#include <errno.h>
//#include <string.h>

/*printf("%s\n", strerror(errno));*/