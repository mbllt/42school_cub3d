#include "cub3D.h"

static void	move_bis3(t_vars *cub, t_vector temp_dir_ray)
{
	if (cub->ray_c.key.right == 1 && check_collision(cub, temp_dir_ray, 2) == 1)
	{
		if (cub->ray_c.key.speed == 1)
		{
			cub->parsing.px -= temp_dir_ray.y * MOVE_SPEED * 1.5;
			cub->parsing.py += temp_dir_ray.x * MOVE_SPEED * 1.5;
		}
		cub->parsing.px -= temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.x * MOVE_SPEED;
	}
	if (cub->ray_c.key.left == 1 && check_collision(cub, temp_dir_ray, 3) == 1)
	{
		if (cub->ray_c.key.speed == 1)
		{
			cub->parsing.px += temp_dir_ray.y * MOVE_SPEED * 1.5;
			cub->parsing.py -= temp_dir_ray.x * MOVE_SPEED * 1.5;
		}
		cub->parsing.px += temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.x * MOVE_SPEED;
	}
}

static void	move_bis2(t_vars *cub, t_vector temp_dir_ray)
{
	if (cub->ray_c.key.up == 1 && cub->parsing.pz + MOVE_SPEED < 1)
		cub->parsing.pz += MOVE_SPEED;
	if (cub->ray_c.key.down == 1 && cub->parsing.pz + MOVE_SPEED > 0.5)
		cub->parsing.pz -= MOVE_SPEED;
	if (cub->ray_c.key.jump == 1 && cub->parsing.pz + MOVE_SPEED < 0.85)
		cub->parsing.pz += MOVE_SPEED;
	if (cub->ray_c.key.jump == 0 && cub->parsing.pz + MOVE_SPEED > 0.5)
		cub->parsing.pz -= MOVE_SPEED;
	move_bis3(cub, temp_dir_ray);
}

static void	move_bis(t_vars *cub, t_vector temp_dir_ray)
{
	if (cub->ray_c.key.backward == 1 && check_collision(cub, temp_dir_ray, \
		1) == 1)
	{
		if (cub->ray_c.key.speed == 1)
		{
			cub->parsing.px -= temp_dir_ray.x * MOVE_SPEED * 1.5;
			cub->parsing.py -= temp_dir_ray.y * MOVE_SPEED * 1.5;
		}
		cub->parsing.px -= temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.y * MOVE_SPEED;
	}
	move_bis2(cub, temp_dir_ray);
}

void	move(t_vars *cub)
{
	t_vector	temp_dir_ray;

	temp_dir_ray = cub->ray_c.ray_dir;
	temp_dir_ray = rotation_z(cub, (t_vector){0, -1, 0});
	if (cub->ray_c.key.forward == 1 && check_collision(cub, temp_dir_ray, \
		0) == 1)
	{
		if (cub->ray_c.key.speed == 1)
		{
			cub->parsing.px += temp_dir_ray.x * MOVE_SPEED * 1.5;
			cub->parsing.py += temp_dir_ray.y * MOVE_SPEED * 1.5;
		}
		cub->parsing.px += temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.y * MOVE_SPEED;
	}
	move_bis(cub, temp_dir_ray);
}
