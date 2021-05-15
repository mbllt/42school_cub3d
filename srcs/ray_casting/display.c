#include "cub3D.h"

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	F,
	C,
}t_dir;

void	display(t_vars *cub, int i, int j, int orienta_wall)
{
	if (orienta_wall == NORTH)
	{
		//printf("%d\n", orienta_wall);
		my_mlx_pixel_put(cub, i, j, TEAL);
	}
	else if (orienta_wall == SOUTH)
	{
		my_mlx_pixel_put(cub, i, j, PINK);
	}
	else if (orienta_wall == EAST)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, BROWN);
	}
	else if (orienta_wall == WEST)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, ORANGE);
	}
	else if (orienta_wall == F)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, GREEN);
	}
	else if (orienta_wall == C)
	{
		//printf("yoy\n");
		my_mlx_pixel_put(cub, i, j, BLUE);
	}
	else
		my_mlx_pixel_put(cub, i, j, GREY);
	// if (orienta_wall == -1)
	// 	printf("%d\n", orienta_wall);
}