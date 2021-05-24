#include "cub3D.h"
#include <errno.h>
#include <string.h>

int	save_bitmap(t_vars *cub)
{
	int				i;
	int				j;
	int				ret;
	unsigned char	buffer[3];

	i = cub->parsing.ry;
	while (--i >= 0)
	{
		buffer[0] = 0;
		buffer[1] = 0;
		buffer[2] = 0;
		j = 0;
		while (j < cub->parsing.rx)
		{
			buffer[0] = cub->pixel_data[j][i] & 0x000000FF;
			buffer[1] = cub->pixel_data[j][i] >> 8;
			buffer[2] = cub->pixel_data[j][i] >> 16;
			ret = write(cub->fd, &buffer, 3);
			if (ret < 0)
			{
				close(cub->fd);
				ft_exit(cub);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	save_header(t_vars *cub)
{
	int	ret_write;

	cub->fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXO);
	if (cub->fd < 0)
	{
		return (0);
	}
	ret_write = write(cub->fd, &cub->save, 14 + 40);
	if (ret_write < 0)
	{
		return (0);
	}
	return (1);
}
