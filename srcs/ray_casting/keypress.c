#include "cub3D.h"

static void	key_press2(int key, t_vars *cub)
{
	if (key == EXIT)
	{
		cub->ray_c.key.exit = 1;
		cub->exit_good = 1;
	}
	if (key == JUMP)
		cub->ray_c.key.jump = 1;
	if (key == SPEED)
		cub->ray_c.key.speed = 1;
}

int	key_press(int key, t_vars *cub)
{
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
	key_press2(key, cub);
	return (1);
}

int	key_release(int key, t_vars *cub)
{
	if (key == O)
		cub->ray_c.key.up = 0;
	if (key == L)
		cub->ray_c.key.down = 0;
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
	if (key == JUMP)
		cub->ray_c.key.jump = 0;
	if (key == SPEED)
		cub->ray_c.key.speed = 0;
	return (1);
}

static void	rotate2(t_vars *cub)
{
	if (cub->ray_c.key.rot_z_right == 1)
	{
		if (cub->ray_c.rota_z + MOVE_SPEED > 360 * (M_PI / 180))
			cub->ray_c.rota_z -= 360 * (M_PI / 180);
		cub->ray_c.rota_z += MOVE_SPEED;
		init_matrix_z(cub);
	}
	if (cub->ray_c.key.rot_z_left == 1)
	{
		if (cub->ray_c.rota_z - MOVE_SPEED < - (360 * (M_PI / 180)))
			cub->ray_c.rota_z += 360 * (M_PI / 180);
		cub->ray_c.rota_z -= MOVE_SPEED;
		init_matrix_z(cub);
	}
}

void	rotate(t_vars *cub)
{
	if (cub->ray_c.key.rot_x_right == 1)
	{
		if (cub->ray_c.rota_x + MOVE_SPEED < 0.7)
		{
			cub->ray_c.rota_x += MOVE_SPEED;
			init_matrix_x(cub);
		}
	}
	if (cub->ray_c.key.rot_x_left == 1)
	{
		if (cub->ray_c.rota_x - MOVE_SPEED > -0.7)
		{
			cub->ray_c.rota_x -= MOVE_SPEED;
			init_matrix_x(cub);
		}
	}
	rotate2(cub);
}
