#include "cub3D.h"

#define FRONT 0
#define BACK 1
#define RIGHT 2
#define LEFT 3
#define MOVE_SPEED 0.12

static int	check_space_move(t_vars *cub, t_vector temp)
{
	if ((int)temp.x >= cub->parsing.map_x || (int)temp.x < 0 \
		|| (int)temp.y >= cub->parsing.map_y || (int)temp.y < 0 \
		|| (cub->parsing.world_map[(int)cub->parsing.py][(int)temp.x] == '1' \
		&& cub->parsing.world_map[(int)temp.y][(int)cub->parsing.px] == '1') \
		|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == '1' \
		|| cub->parsing.world_map[(int)temp.y][(int)temp.x] == ' ')
		return (0);
	else if (cub->parsing.world_map[(int)temp.y][(int)temp.x] == '2')
 	{
 		write(1, "\n\e[33m       ﾍ(￣▽￣*)ﾉ\n\n", 34);
 		write(1, "\033[31mYou're dead, try again !\033[0m\n", 35);
 		ft_exit(cub);
 	}
	return (1);
}

int	check_collision(t_vars *cub, t_vector temp_dir_ray, int key)
{
	t_vector	temp;

	temp.x = cub->parsing.px;
	temp.y = cub->parsing.py;
	if (key == FRONT)
	{
		temp.x += temp_dir_ray.x * MOVE_SPEED;
		temp.y += temp_dir_ray.y * MOVE_SPEED;
	}
	else if (key == BACK)
	{
		temp.x -= temp_dir_ray.x * MOVE_SPEED;
		temp.y -= temp_dir_ray.y * MOVE_SPEED;
	}
	if (key == RIGHT)
	{
		temp.x -= temp_dir_ray.y * MOVE_SPEED;
		temp.y += temp_dir_ray.x * MOVE_SPEED;
	}
	else if (key == LEFT)
	{
		temp.x += temp_dir_ray.y * MOVE_SPEED;
		temp.y -= temp_dir_ray.x * MOVE_SPEED;
	}
	return (check_space_move(cub, temp));
}

void	change_ray_dir(t_vars *cub, char c)
{
	float	temp;

	temp = cub->ray_c.rota_z;
	if (c == 'S')
	{
		cub->ray_c.rota_z = M_PI;
		init_matrix_z(cub);
	}
	if (c == 'E')
	{
		cub->ray_c.rota_z = M_PI * 0.5;
		init_matrix_z(cub);
	}
	if (c == 'W')
	{
		cub->ray_c.rota_z = M_PI * 1.5;
		init_matrix_z(cub);
	}
}

void	my_mlx_pixel_put_bis(t_text text, int x, int y, unsigned int color)
{
	char	*dst;
	int		temp;

	temp = y * text.line_length + x * (text.bits_per_pixel * 0.125);
	dst = (char *)text.addr + temp;
	*(unsigned int *)dst = color;
}

void	ft_destroy(t_vars *cub)
{
	if (mlx_destroy_image(cub->ray_c.mlx, cub->ray_c.img))
		write(1, "\nDestroy image did not work\n", 27);
	if (mlx_destroy_window(cub->ray_c.mlx, cub->ray_c.win))
		write(1, "\nDestroy window did not work\n", 28);
}
