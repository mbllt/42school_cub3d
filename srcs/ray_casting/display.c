#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dir;

void	display(t_vars *cub, int i, int j, int orienta_wall)
{
	if (orienta_wall == NORTH)
	{
		//printf("%d\n", orienta_wall);
		my_mlx_pixel_put(cub, i, j, TEAL);
	}
	if (orienta_wall == SOUTH)
	{
		my_mlx_pixel_put(cub, i, j, PINK);
	}
	if (orienta_wall == EAST)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, BROWN);
	}
	if (orienta_wall == WEST)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, ORANGE);
	}
}