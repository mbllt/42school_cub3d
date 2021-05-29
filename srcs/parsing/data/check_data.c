#include "cub3D.h"

static int	check_data_param_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i] == '\n')
		return (1);
	if ((is_param(line[i])) == 1)
		return (1);
	else if (line[i] && line[i] == '1')
	{
		return (1);
	}
	else if (line[i])
	{
		write(1, "\nInvalid parameter in parsing\n", 30);
		return (0);
	}
	return (1);
}

static int	check_nbr_param_and_order(t_vars *cub, char *line, int ret)
{
	static int	nbr_param = 0;
	static int	order = 0;
	int			i;

	i = 0;
	while (ret > 0 && line[i] == ' ')
		i++;
	if (ret > 0 && (is_param(line[i]) == 1) && order == 0)
		nbr_param++;
	else if (ret > 0 && (is_param(line[i]) == 1) && order != 0)
		return (-1);
	else if (order && !line[0])
		cub->parsing.zero++;
	if (ret > 0 && line[i] == '1')
		order++;
	if (ret == 0 && (nbr_param != 8 || !order))
		return (-1);
	return (1);
}

int	check_data(t_vars *cub, char *line, int ret)
{
	static int	nbr = 0;

	if (ret > 0 && (!check_data_param_valid(line)))
		return (0);
	else
	{
		if (is_res_or_colors(line) && !(check_res_color(cub, line)))
			return (0);
		if (is_path_textures(line) && !(check_path_textures(cub, line)))
			return (0);
	}
	nbr = check_nbr_param_and_order(cub, line, ret);
	if (nbr == -1)
	{
		write(1, "\nError : parsing\n", 17);
		return (0);
	}
	return (1);
}
