#include "cub3D.h"

// typedef enum e_dir
// {
// 	NORTH,
// 	SOUTH,
// 	EAST,
// 	WEST,
// }t_dir;

static void	fill_in_path(t_vars *cub, int nbr, char *str)
{
	if (nbr == NORTH)
		cub->parsing.no = str;
	else if (nbr == SOUTH)
		cub->parsing.so = str;
	else if (nbr == EAST)
		cub->parsing.we = str;
	else if (nbr == WEST)
		cub->parsing.ea = str;
}

int	get_path_nsew(t_vars *cub, char *line, int *i, int nbr_path)
{
	char	*str;
	int		j;

	str = NULL;
	j = 2;
	while (line[(*i)] != ' ' && line[(*i)] != '\n')
	{
		if (!str)
		{
			str = malloc(sizeof(char) * j);
			if (!str)
				return (0);
		}
		else
		{
			str = ft_realloc(str, j + 1);
			if (!str)
				return (0);
		}
		str[j] = line[(*i)];
		str[j + 1] = 0;
		fill_in_path(cub, nbr_path, str);
		(*i)++;
		j++;
	}
	return (1);
}