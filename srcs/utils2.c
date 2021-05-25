#include "cub3D.h"

void	ft_double_free(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, unsigned int color)
{
	char	*dst;
	int		temp;

	temp = y * mlx->ray_c.line_length + x * (mlx->ray_c.bits_per_pixel * 0.125);
	dst = mlx->ray_c.addr + temp;
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_text texture, int x, int y)
{
	int	temp;

	if (!(x >= 0 && y >= 0 && x < texture.width && y < texture.height))
		return (0);
	temp = y * (texture.line_length * 0.25) + x;
	return (texture.addr[temp]);
}

t_vector	get_ray_temp(void *thread_data, int x, int y)
{
	t_vector	ray_temp;

	ray_temp = ((t_thread *)thread_data)->cub.ray_c.stock_rays[x][y];
	ray_temp = rotation_x(&((t_thread *)thread_data)->cub, ray_temp);
	ray_temp = rotation_z(&((t_thread *)thread_data)->cub, ray_temp);
	return (ray_temp);
}

float	get_r(t_vars *cub, t_dot_intersct *intersct, int i)
{
	t_vector	u;
	float		r;

	u = (t_vector){
		.x = intersct->dot.x - cub->ray_c.sprite[i].pos.x,
		.y = intersct->dot.y - cub->ray_c.sprite[i].pos.y,
		.z = 0
	};
	r = scalaire_v(u, cub->ray_c.sprite[i].v2) + 0.5;
	return (r);
}
