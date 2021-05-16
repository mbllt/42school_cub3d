#include "cub3D.h"

static	int	get_textures_img(t_vars *cub, int i)
{
	//printf("i : %d\n", i);
	cub->parsing.textures[i].img = mlx_xpm_file_to_image(cub->ray_c.mlx, cub->parsing.no, \
									cub->parsing.textures[i].width, \
									cub->parsing.textures[i].height);
	if (!(cub->parsing.textures[i].img))
	{
		write(1, "Error : textures\n", 18);
		return (0);
	}
	return (1);
}

int	get_textures(t_vars *cub)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (!(get_textures_img(cub, i)))
			return (0);
	return (1);
}
