#include "cub3D.h"

static void	check_size(char **str)
{
	if (ft_strlen(*str) > 8)
		(*str)[8] = 0;
}

int	check_get_res(t_vars *cub, char **str, int size)
{
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
	if (!(is_pos(cub->parsing.rx)) || !(is_pos(cub->parsing.ry)))
		return (0);
	return (1);
}