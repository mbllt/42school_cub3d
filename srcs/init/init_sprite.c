#include "cub3D.h"

static t_vector	*ft_realloc_sprite(t_vector *sprite, int size_src, int size_dst)
{
	t_vector	*temp;
	int			i;

	if (!(sprite))
		return (NULL);
	if (!(temp = malloc(sizeof(t_vector) * size_dst)))
		return (NULL);
	i = 0;
	while (i < size_src)
	{
		temp[i] = sprite[i];
		i++;
	}
	if (sprite)
		free(sprite);
	return (temp);
}

int	init_sprite(t_vars *cub, char **world_map)
{
	int	x;
	int	y;
	int	i;

	i = 1;
	y = -1;
	while (++y < cub->parsing.map_y)
	{
		x = -1;
		while (++x < cub->parsing.map_x)
		{
			if (world_map[y][x] == '2')
			{
				if (i == 1)
					cub->ray_c.sprite_p = malloc(sizeof(t_vector) * i);
				if (!cub->ray_c.sprite_p)
					return (0);
				else
					cub->ray_c.sprite_p = ft_realloc_sprite(cub->ray_c.sprite_p, i - 1, i);
				if (!cub->ray_c.sprite_p)
					return (0);
				cub->ray_c.sprite_p[i - 1].y = y + 0.5;
				cub->ray_c.sprite_p[i - 1].x = x + 0.5;
				i++;
			}
		}
	}
	cub->ray_c.nbr_sprite = i - 1;
	if (cub->ray_c.nbr_sprite != 0)
		for (int i = 0;i < cub->ray_c.nbr_sprite;i++)
			printf("sprite[%d] = x :%f, y :%f || %d\n", i, cub->ray_c.sprite_p[i].x, cub->ray_c.sprite_p[i].y, cub->ray_c.nbr_sprite);
	return (1);
}
