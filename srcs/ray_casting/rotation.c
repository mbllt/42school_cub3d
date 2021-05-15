#include "cub3D.h"

void	rotation_x(t_vars *cub, t_vector *ray)
{
	t_vector	bis;

	bis = (*ray);
	ray->x = 0;
	ray->x += cub->ray_c.matrix_x[0][0] * bis.x;
	ray->x += cub->ray_c.matrix_x[0][1] * bis.y;
	ray->x += cub->ray_c.matrix_x[0][2] * bis.z;
	ray->y = 0;
	ray->y += cub->ray_c.matrix_x[1][0] * bis.x;
	ray->y += cub->ray_c.matrix_x[1][1] * bis.y;
	ray->y += cub->ray_c.matrix_x[1][2] * bis.z;
	ray->z = 0;
	ray->z += cub->ray_c.matrix_x[2][0] * bis.x;
	ray->z += cub->ray_c.matrix_x[2][1] * bis.y;
	ray->z += cub->ray_c.matrix_x[2][2] * bis.z;
	// if ((*ray).x == bis.x && (*ray).y == bis.y && (*ray).z == bis.x)
	// 	printf("same\n");
	//return (ray);
}

void	rotation_z(t_vars *cub, t_vector *ray)
{
	t_vector	bis;

	bis = (*ray);
	ray->x = 0;
	ray->x += cub->ray_c.matrix_z[0][0] * bis.x;
	//printf("%f\n", cub->ray_c.matrix_z[1][1]);
	//printf("%f\n", cos(0.3));
	ray->x += cub->ray_c.matrix_z[0][1] * bis.y;
	ray->x += cub->ray_c.matrix_z[0][2] * bis.z;
	ray->y = 0;
	ray->y += cub->ray_c.matrix_z[1][0] * bis.x;
	ray->y += cub->ray_c.matrix_z[1][1] * bis.y;
	ray->y += cub->ray_c.matrix_z[1][2] * bis.z;
	ray->z = 0;
	ray->z += cub->ray_c.matrix_z[2][0] * bis.x;
	ray->z += cub->ray_c.matrix_z[2][1] * bis.y;
	ray->z += cub->ray_c.matrix_z[2][2] * bis.z;
	// if ((*ray).x == bis.x && (*ray).y == bis.y && (*ray).z == bis.x)
	// 	printf("same\n");
	//return (ray);
}