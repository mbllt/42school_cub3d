#include "cub3D.h"

static int	check_data_param_valid(char *line, int *part_map)
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
		(*part_map)++;
		return (1);
	}
	else if (line[i])
	{
		write(1, "\nInvalid parameter in parsing\n", 30);
		return (0);
	}
	return (1);
}

// static int	check_map_space(char *line, int part_map)
// {
// 	if (part_map && line[0] == 0)
// 	{
		// write(1, "\nWrong map\n", 11);
		// return (0);
// 	}
// }

static int	check_nbr_param_and_order(char *line, int ret)
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
	else if (ret == 0 && order && !line[0])
		return (-1);
	if (ret > 0 && line[i] == '1')
		order++;
	if (ret == 0 && (nbr_param != 8 || !order))
		return (-1);
	return (1);
}

int	check_data(t_vars *cub, char *line, int ret)
{
	static int	nbr = 0;
	static int	part_map = 0;

	if (ret > 0 && part_map == 0 && (!check_data_param_valid(line, &part_map)))
		return (0);
	else
	{
		if (is_res_or_colors(line))
			if (!(check_res_color(cub, line)))
				return (0);
		if (is_path_textures(line))
			if (!(check_path_textures(cub, line)))
					return (0);
	}
	nbr = check_nbr_param_and_order(line, ret);
	if (nbr == -1)
	{
		write(1, "\nError : parsing\n", 17);
		return (0);
	}
	if (part_map == 1 && line[0] == 0)
	{
		write(1, "\nWrong map\n", 11);
		return (0);
	}
	return (1);
}