#include "cub3D.h"

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

static void	check_collision2(t_vars *cub, t_vector temp_dir_ray, int key, \
		t_vector *temp)
{
	float		speed;

	speed = MOVE_SPEED * 2;
	if (cub->ray_c.key.speed == 1)
		speed *= 2;
	if (key == cub->ray_c.move.right)
	{
		temp->x -= temp_dir_ray.y * speed;
		temp->y += temp_dir_ray.x * speed;
	}
	else if (key == cub->ray_c.move.left)
	{
		temp->x += temp_dir_ray.y * speed;
		temp->y -= temp_dir_ray.x * speed;
	}
}

int	check_collision(t_vars *cub, t_vector temp_dir_ray, int key)
{
	t_vector	temp;
	float		speed;

	temp.x = cub->parsing.px;
	temp.y = cub->parsing.py;
	speed = MOVE_SPEED * 2;
	if (cub->ray_c.key.speed == 1)
		speed *= 2;
	if (key == cub->ray_c.move.front)
	{
		temp.x += temp_dir_ray.x * speed;
		temp.y += temp_dir_ray.y * speed;
	}
	else if (key == cub->ray_c.move.back)
	{
		temp.x -= temp_dir_ray.x * speed;
		temp.y -= temp_dir_ray.y * speed;
	}
	check_collision2(cub, temp_dir_ray, key, &temp);
	return (check_space_move(cub, temp));
}
