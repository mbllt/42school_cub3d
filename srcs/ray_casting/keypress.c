#include "cub3D.h"

#define KEYUP		126
#define KEYDOWN		125
#define KEYRIGHT	124
#define KEYLEFT		123
#define W			13
#define S			1
#define D			2
#define A			0
#define O			31
#define L			37
#define MOVE_SPEED	0.09

int	key_press(int key, t_vars *cub)
{
	if (key == W)
		cub->ray_c.key.forward = 1;
	if (key == S)
		cub->ray_c.key.backward = 1;
	if (key == D)
		cub->ray_c.key.right = 1;
	if (key == A)
		cub->ray_c.key.left = 1;
	if (key == KEYUP)
		cub->ray_c.key.rot_x_left = 1;
	if (key == KEYDOWN)
		cub->ray_c.key.rot_x_right = 1;
	if (key == KEYLEFT)
		cub->ray_c.key.rot_z_left = 1;
	if (key == KEYRIGHT)
		cub->ray_c.key.rot_z_right = 1;
	if (key == 53)
		cub->ray_c.key.exit = 1;
	return (1);
}

int	key_release(int key, t_vars *cub)
{
	if (key == W)
		cub->ray_c.key.forward = 0;
	if (key == S)
		cub->ray_c.key.backward = 0;
	if (key == D)
		cub->ray_c.key.right = 0;
	if (key == A)
		cub->ray_c.key.left = 0;
	if (key == KEYLEFT)
		cub->ray_c.key.rot_z_left = 0;
	if (key == KEYRIGHT)
		cub->ray_c.key.rot_z_right = 0;
	if (key == KEYUP)
		cub->ray_c.key.rot_x_left = 0;
	if (key == KEYDOWN)
		cub->ray_c.key.rot_x_right = 0;
	return (1);
}

static void	move_right_left(t_vars *cub, t_vector temp_dir_ray, t_vector temp)
{
	if (cub->ray_c.key.right == 1 && check_collision(cub, temp_dir_ray, 2, \
		temp) == 1)
	{
		cub->parsing.px -= temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.x * MOVE_SPEED;
	}
	if (cub->ray_c.key.left == 1 && check_collision(cub, temp_dir_ray, 3, \
		temp) == 1)
	{
		cub->parsing.px += temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.x * MOVE_SPEED;
	}
}

void	move(t_vars *cub)
{
	t_vector	temp_dir_ray;
	t_vector	temp;

	// temp_dir_ray = (t_vector){0, -1, 0};
	temp_dir_ray = cub->ray_c.ray_dir;
	//printf("(%f,%f,%f)\n", cub->ray_c.ray_dir.x, cub->ray_c.ray_dir.y, cub->ray_c.ray_dir.z);
	// cub->ray_c.rota_z = 0.09;
	// init_matrix_z(cub);
	temp_dir_ray = rotation_z(cub, (t_vector){0, -1, 0});
	//printf("here!!!\n");
	temp = (t_vector){cub->parsing.px, cub->parsing.py, 0};
	if (cub->ray_c.key.forward == 1 && check_collision(cub, temp_dir_ray, 0, \
		temp) == 1)
	{
		cub->parsing.px += temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.y * MOVE_SPEED;
	}
	if (cub->ray_c.key.backward == 1 && check_collision(cub, temp_dir_ray, 1, \
		temp) == 1)
	{
		cub->parsing.px -= temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.y * MOVE_SPEED;
	}
	move_right_left(cub, temp_dir_ray, temp);
}

void	rotate(t_vars *cub)
{
	if (cub->ray_c.key.rot_x_right == 1)
	{
		cub->ray_c.rota_x += MOVE_SPEED;
		init_matrix_x(cub);
	}
	if (cub->ray_c.key.rot_x_left == 1)
	{
		cub->ray_c.rota_x -= MOVE_SPEED;
		init_matrix_x(cub);
	}
	if (cub->ray_c.key.rot_z_right == 1)
	{
		cub->ray_c.rota_z += MOVE_SPEED;
		init_matrix_z(cub);
	}
	if (cub->ray_c.key.rot_z_left == 1)
	{
		cub->ray_c.rota_z -= MOVE_SPEED;
		init_matrix_z(cub);
	}
}
