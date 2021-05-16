#include "cub3D.h"

t_vector	rotation_x(t_vars *cub, t_vector ray)
{
	t_vector	bis;
	t_vector	temp;

	bis = ray;
	temp = ray;
	bis.x = 0;
	bis.x += cub->ray_c.matrix_x[0][0] * temp.x;
	bis.x += cub->ray_c.matrix_x[0][1] * temp.y;
	bis.x += cub->ray_c.matrix_x[0][2] * temp.z;
	bis.y = 0;
	bis.y += cub->ray_c.matrix_x[1][0] * temp.x;
	bis.y += cub->ray_c.matrix_x[1][1] * temp.y;
	bis.y += cub->ray_c.matrix_x[1][2] * temp.z;
	bis.z = 0;
	bis.z += cub->ray_c.matrix_x[2][0] * temp.x;
	bis.z += cub->ray_c.matrix_x[2][1] * temp.y;
	bis.z += cub->ray_c.matrix_x[2][2] * temp.z;
	// if ((*ray).x == bis.x && (*ray).y == bis.y && (*ray).z == bis.x)
	// 	printf("same\n");
	return (bis);
}

t_vector	rotation_z(t_vars *cub, t_vector ray)
{
	t_vector	bis;
	t_vector	temp;

	bis = ray;
	temp = ray;
	bis.x = 0;
	bis.x += cub->ray_c.matrix_z[0][0] * temp.x;
	bis.x += cub->ray_c.matrix_z[0][1] * temp.y;
	bis.x += cub->ray_c.matrix_z[0][2] * temp.z;
	bis.y = 0;
	bis.y += cub->ray_c.matrix_z[1][0] * temp.x;
	bis.y += cub->ray_c.matrix_z[1][1] * temp.y;
	bis.y += cub->ray_c.matrix_z[1][2] * temp.z;
	bis.z = 0;
	bis.z += cub->ray_c.matrix_z[2][0] * temp.x;
	bis.z += cub->ray_c.matrix_z[2][1] * temp.y;
	bis.z += cub->ray_c.matrix_z[2][2] * temp.z;
	// if ((*ray).x == bis.x && (*ray).y == bis.y && (*ray).z == bis.x)
	// 	printf("same\n");
	//printf("%f\n", cub->ray_c.rota_z);
	//printf("%f %f\n", (cos(0.03) + cos(0.03)), (cos(0.06) + cos(0.008)));
	return (bis);
}