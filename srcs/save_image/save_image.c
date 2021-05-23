#include "cub3D.h"

static unsigned int	**fill_in_str(t_vars *cub, unsigned int **data)
{
	unsigned int	**temp;
	int				i;
	int				j;

	temp = NULL;
	i = 0;
	while (i < cub->parsing.ry)
	{
		j = 0;
		while (j < cub->parsing.rx)
		{
			temp[i][j] = data[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

int	save_image(t_vars *cub)
{
	int				fd;
	int				ret_write;
	unsigned int	**temp;

	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, 00777); /* try with S_IRWXO */
	if (fd < 0)
		return (0);
	ret_write = write(fd, (char *)&cub->save, sizeof(cub->save));
	if (ret_write < 0)
		return (0);
	temp = fill_in_str(cub, cub->pixel_data);
	ret_write = write(fd, (char *)&temp, (cub->parsing.rx * cub->parsing.ry) * 4);
	if (ret_write < 0)
		return (0);
	close(fd);
	return (1);
}

//#include <errno.h>
//#include <string.h>

/*printf("%s\n", strerror(errno));*/