#include "cub3D.h"

int	is_color_path(char *str)
{
	char	c;
	int		i;

	c = ',';
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	create_image_color(t_vars *cub, unsigned int color, int nbr)
{
	(void)color;
	if (nbr == 4)
	{
		cub->parsing.f_img = mlx_new_image(cub->parsing.f_ptr, 1, 1);
		my_mlx_pixel_put(cub->parsing.f_img, 0, 0, cub->parsing.ff);
	}
	if (nbr == 5)
	{
		cub->parsing.c_img = mlx_new_image(cub->parsing.f_ptr, 1, 1);
		my_mlx_pixel_put(cub->parsing.c_img, 0, 0, cub->parsing.cc);
	}
}

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
