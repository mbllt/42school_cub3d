#include "cub3D.h"

static void	check_size(char **str)
{
	if (ft_strlen(*str) > 8)
		(*str)[8] = 0;
}

static void	check_size_res_x(int *nbr, int size_screen_x)
{
	if ((*nbr) > size_screen_x)
		(*nbr) = size_screen_x;
}

static void	check_size_res_y(int *nbr, int size_screen_y)
{
	if ((*nbr) > size_screen_y)
		(*nbr) = size_screen_y;
}

static void	resize_if_too_big(t_vars *cub)
{
	if (cub->parsing.rx > 500 && cub->parsing.ry > 500)
	{
		cub->parsing.rx = ceil(cub->parsing.rx * 0.5);
		cub->parsing.ry = ceil(cub->parsing.ry * 0.5);
		cub->parsing.scale_on = 1;
	}
}

int	check_get_res(t_vars *cub, char **str, int size)
{
	int	size_screen_x;
	int	size_screen_y;

	if (size != 3)
		return (0);
	if (str[0][1] != 0)
		return (0);
	if (!(check_if_not_digit(str[1])) \
		|| !(check_if_not_digit(str[2])))
		return (0);
	check_size(&str[1]);
	check_size(&str[2]);
	cub->parsing.rx = ft_atoi(str[1]);
	cub->parsing.ry = ft_atoi(str[2]);
	size_screen_x = 0;
	size_screen_y = 0;
	mlx_get_screen_size(cub->ray_c.mlx, &size_screen_x, &size_screen_y);
	check_size_res_x(&cub->parsing.rx, size_screen_x);
	check_size_res_y(&cub->parsing.ry, size_screen_y);
	if (!(is_pos(cub->parsing.rx)) || !(is_pos(cub->parsing.ry)))
		return (0);
	cub->parsing.old_rx = cub->parsing.rx;
	cub->parsing.old_ry = cub->parsing.ry;
	resize_if_too_big(cub);
	return (1);
}