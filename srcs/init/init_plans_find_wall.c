#include "cub3D.h"

typedef enum e_dirr
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}t_dirr;

static void	ft_bzero(void *s, size_t n)
{
	t_plan	*c;

	c = (t_plan *)s;
	while (n-- > 0)
		c[n] = (t_plan){5,5,5,5};
}


t_plan	*find_walls_n(t_vars *cub, int size)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	x = 0;
	while (x < cub->parsing.map_x)
	{
		zero = 0;
		y = cub->parsing.map_y - 1;
		while (y >= 0)
		{
			if (cub->parsing.world_map[y][x] == '0' || (is_cardinal(cub->parsing.world_map[y][x])) >= 0)
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0 \
				&& y < cub->parsing.map_y - 1 \
				&& cub->parsing.world_map[y + 1][x] != '1' \
				&& str[y].d == 5)
			{
				// printf("COLONE :%d\n", y);
				// for (int k = 0;k < cub->parsing.map_x;k++)
				// {
				// 	printf("%c\n", cub->parsing.world_map[k][x]);
				// }
				// printf("LIGNE %d\n", x);
				// printf("------------------\n");
				str[y + 1] = (t_plan){0,1,0,(-1) * (y + 1)}; /* x a la place de d*/
			}
			y--;
		}
		x++;
	}
	return (str);
}

t_plan	*find_walls_s(t_vars *cub, int size)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	x = 0;
	while (x < cub->parsing.map_x)
	{
		zero = 0;
		y = 0;
		while (y < cub->parsing.map_y)
		{
			if (cub->parsing.world_map[y][x] == '0' || (is_cardinal(cub->parsing.world_map[y][x])) >= 0)
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0&& y > 0 \
				&& cub->parsing.world_map[y - 1][x] != '1' \
				&& str[y].d == 5)
			{
				// printf("COLONE :%d\n", y);
				// for (int k = 0;k < cub->parsing.map_x;k++)
				// {
				// 	printf("%c\n", cub->parsing.world_map[k][x]);
				// }
				// printf("LIGNE %d\n", x);
				// printf("------------------\n");
				str[y] = (t_plan){0,1,0,(-1) * y}; /* x a la place de d*/
			}
			y++;
		}
		x++;
	}
	return (str);
}

t_plan	*find_walls_e(t_vars *cub, int size)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	y = 0;
	while (y < cub->parsing.map_y)
	{
		zero = 0;
		x = 0;
		while (x < cub->parsing.map_x)
		{
			if (cub->parsing.world_map[y][x] == '0' || (is_cardinal(cub->parsing.world_map[y][x])) >= 0)
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0 && x > 0 \
				&& cub->parsing.world_map[y][x - 1] != '1' \
				&& str[x].d == 5)
			{
				// printf("COLONE :%d\n", x);
				// for (int k = 0;k < cub->parsing.map_y;k++)
				// {
				// 	printf("%c\n", cub->parsing.world_map[k][x]);
				// }
				// printf("LIGNE %d\n", y);
				// printf("------------------\n");
				str[x] = (t_plan){1,0,0,(-1) * x}; /* y a la place de d*/
			}
			x++;
		}
		y++;
	}
	return (str);
}

t_plan	*find_walls_w(t_vars *cub, int size)
{
	int		x;
	int		y;
	int		zero;
	t_plan	*str;

	str = malloc(sizeof(t_plan) * size);
	if (!str)
		return (0);
	ft_bzero(str, size);
	y = 0;
	while (y < cub->parsing.map_y)
	{
		zero = 0;
		x = cub->parsing.map_x - 1;
		while (x >= 0)
		{
			if (cub->parsing.world_map[y][x] == '0' || (is_cardinal(cub->parsing.world_map[y][x])) >= 0)
				zero++;
			if (cub->parsing.world_map[y][x] == '1' && zero != 0 \
				&& x < cub->parsing.map_x - 1 \
				&& cub->parsing.world_map[y][x + 1] != '1' \
				&& str[x].d == 5)
			{
				// printf("COLONE :%d\n", x);
				// for (int k = 0;k < cub->parsing.map_y;k++)
				// {
				// 	printf("%c\n", cub->parsing.world_map[k][x]);
				// }
				// printf("LIGNE %d\n", y);
				// printf("------------------\n");
				str[x + 1] = (t_plan){1,0,0,(-1) * (x + 1)}; /* x a la place de d*/
			}
			x--;
		}
		y++;
	}
	return (str);
}