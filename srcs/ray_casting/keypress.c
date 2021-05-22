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
	// if (time(NULL) == cub->seconde)
	// 	cub->fps++;
	// else
	// 	printf("fps : %d\n", cub->fps);
	if (key == O)
		cub->ray_c.key.up = 1;
	if (key == L)
		cub->ray_c.key.down = 1;
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
	//printf("%d\n", key);
	// if (!(graphical_loop(cub, cub->parsing.rx, cub->parsing.ry)))
	// 	return (0);
	return (1);
}

int	key_release(int key, t_vars *cub)
{
	// if (key == O)
	// 	cub->ray_c.key.up = 0;
	// if (key == L)
	// 	cub->ray_c.key.down = 0;
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

static void	move_right_left(t_vars *cub, t_vector temp_dir_ray)
{
	if (cub->ray_c.key.right == 1)
	{
		cub->parsing.px -= temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.x * MOVE_SPEED;
	}
	if (cub->ray_c.key.left == 1)
	{
		cub->parsing.px += temp_dir_ray.y * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.x * MOVE_SPEED;
	}
}

void	move(t_vars *cub)
{
	t_vector	temp_dir_ray;

	temp_dir_ray = (t_vector){0, -1, 0};
	temp_dir_ray = rotation_z(cub, temp_dir_ray);
	// if (cub->ray_c.key.up == 1)
	// {
	// 	cub->parsing.pz += MOVE_SPEED;
	// }
	// if (cub->ray_c.key.down == 1)
	// {
	// 	cub->parsing.pz -= MOVE_SPEED;
	// }
	if (cub->ray_c.key.forward == 1)
	{
		cub->parsing.px += temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py += temp_dir_ray.y * MOVE_SPEED;
	}
	if (cub->ray_c.key.backward == 1)
	{
		cub->parsing.px -= temp_dir_ray.x * MOVE_SPEED;
		cub->parsing.py -= temp_dir_ray.y * MOVE_SPEED;
	}
	move_right_left(cub, temp_dir_ray);
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
