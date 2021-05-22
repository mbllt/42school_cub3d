#include "cub3D.h"

int	is_res_or_colors(char *line)
{
	int	i;
	char c;

	i = 0;
	while (line[i] == ' ')
		i++;
	c = line[i];
	if (c == 'R' || c == 'F' || c == 'C')
		return (1);
	return (0);
}

int	is_path_textures(char *line)
{
	int	i;
	char c;

	i = 0;
	while (line[i] == ' ')
		i++;
	c = line[i];
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_one(char c)
{
	//printf("%c\n", c);
	if (c == '1')
		return (1);
	return (0);
}

int	is_pos(int nbr)
{
	if (nbr > 0)
		return (1);
	return (0);
}

int	check_nbr_coma(char *str)
{
	int	i;
	int	nbr_coma;

	i = 0;
	nbr_coma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nbr_coma++;
		i++;
	}
	if (nbr_coma != 2)
		return (0);
	return (1);
}