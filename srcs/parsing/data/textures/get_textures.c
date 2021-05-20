#include "cub3D.h"

static	int	get_addr_text(t_text *textures, int i)
{
	textures[i].addr = (unsigned int *)mlx_get_data_addr(textures[i].img, \
										&(textures[i].bits_per_pixel), \
										&(textures[i].line_length), 
										&(textures[i].endian));
	// printf("i :%d\nimg :%p\nwidth :%d, height :%d\naddr :%p\nbpp :%d\nline_lenght :%d\nendian :%d\n\n", \
			// i, textures[i].img, textures[i].width, textures[i].height, textures[i].addr, textures[i].bits_per_pixel, textures[i].line_length, textures[i].endian);
	return (1);
}

int	get_textures(t_vars *cub, t_text *textures)
{
	int	i;

	textures[0].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.no, \
						&textures[0].width, &textures[0].height);
	textures[1].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.so, \
						&textures[1].width, &textures[1].height);
	textures[2].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.ea, \
						&textures[2].width, &textures[2].height);
	textures[3].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.we, \
						&textures[3].width, &textures[3].height);
	textures[4].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.s, \
						&textures[4].width, &textures[4].height);
	i = -1;
	while (++i < 5)
	{
		if (!(textures[i].img))
		{
			write(1, "\nError : textures\n", 19);
			return (0);
		}
	}
	i = -1;
	while (++i < 5)
		if (!(get_addr_text(cub->parsing.textures, i)))
			return (0);
	return (1);
}
