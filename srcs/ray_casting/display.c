#include "cub3D.h"

void	my_mlx_pixel_put(t_vars *mlx, int x, int y, unsigned int color)
{
	if (x >= 0 && y >= 0 && x < mlx->parsing.rx && y < mlx->parsing.ry)
		mlx->ray_c.addr[y * mlx->parsing.rx + x] = color;
}

// void	display(t_vars *cub, int i, int j, t_dot_intersct prio_wall)
// {
// 	int	k;
// 	int	colors[7];

// 	colors[0] = create_trgb(0,255,0,0);
// 	//printf("%d\n", colors[0]);
// 	colors[1] = create_trgb(0,255,0,255);
// 	colors[2] = create_trgb(0,70,100,190);
// 	colors[3] = create_trgb(0,255,255,0);
// 	colors[4] = cub->parsing.ff;
// 	colors[5] = cub->parsing.cc;
// 	colors[6] = create_trgb(0,255,255,200);
// 	k = -1;
// 	while (++k < 7)
// 	{
// 		if (prio_wall.cardinal == k)
// 		{
// 			my_mlx_pixel_put(cub, i, j, (int)colors[k]);
// 		}
// 	}
// 	//printf("%d\n", (int)"0,0,0,255");
// }

static unsigned int	get_pixel(t_text texture, int x, int y)
{
	int	temp;

	temp =  x * (texture.bits_per_pixel * 0.125) + texture.line_length * y;
	return (texture.addr[temp]);
}

static void	get_xy_noso(t_vars *cub, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = cub->ray_c.ray_temp.x - (int)cub->ray_c.ray_temp.x;
	(*x) = (text.width - 1) * decimal;
	(*y) = (text.height - 1) * cub->ray_c.ray_temp.z;
	//printf("%f\n", cub->ray_c.ray_temp.x);
}

static void	get_xy_eawe(t_vars *cub, t_text text, int *x, int *y)
{
	float	decimal;

	decimal = cub->ray_c.ray_temp.y - (int)cub->ray_c.ray_temp.y;
	(*x) = (text.width - 1) * decimal;
	(*y) = (text.height - 1) * cub->ray_c.ray_temp.z;
	//printf("%f\n", cub->ray_c.xyz.x);
}

void	display(t_vars *cub, int i, int j, t_dot_intersct prio_wall)
{
	int				x;
	int				y;
	unsigned int	pixel;

	x = 0;
	y = 0;
	if (prio_wall.cardinal == 0)
	{
		get_xy_noso(cub, cub->parsing.textures[0], &x, &y);
		pixel = get_pixel(cub->parsing.textures[0], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
		//printf("%d, %d\n", x, y);
		//printf("%d\n", (int)pixel);
	}
	else if (prio_wall.cardinal == 1)
	{
		get_xy_noso(cub, cub->parsing.textures[1], &x, &y);
		pixel = get_pixel(cub->parsing.textures[1], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == 2)
	{
		get_xy_eawe(cub, cub->parsing.textures[2], &x, &y);
		pixel = get_pixel(cub->parsing.textures[2], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == 3)
	{
		get_xy_eawe(cub, cub->parsing.textures[3], &x, &y);
		pixel = get_pixel(cub->parsing.textures[3], x, y);
		my_mlx_pixel_put(cub, i, j, (unsigned int)pixel);
	}
	else if (prio_wall.cardinal == 4)
		my_mlx_pixel_put(cub, i, j, cub->parsing.ff);
	else if (prio_wall.cardinal == 5)
		my_mlx_pixel_put(cub, i, j, cub->parsing.cc);
	// else
	// {
	// 	//printf("yoy\n");
	// 	my_mlx_pixel_put(cub, i, j, (unsigned char*)"255,255,255");
	// }
}