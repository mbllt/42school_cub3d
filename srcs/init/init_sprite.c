#include "cub3D.h"

static t_sprite	*ft_realloc_sprite(t_sprite *sprite, int size_src, int size_dst)
{
	t_sprite	*temp;
	int			i;

	if (!(sprite))
		return (NULL);
	if (!(temp = malloc(sizeof(t_sprite) * size_dst)))
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
					cub->ray_c.sprite = malloc(sizeof(t_sprite) * i);
				if (!cub->ray_c.sprite)
					return (0);
				else
					cub->ray_c.sprite = ft_realloc_sprite(cub->ray_c.sprite, i - 1, i);
				if (!cub->ray_c.sprite)
					return (0);
				cub->ray_c.sprite[i - 1].pos.y = y + 0.5;
				cub->ray_c.sprite[i - 1].pos.x = x + 0.5;
				i++;
			}
		}
	}
	cub->ray_c.nbr_sprite = i - 1;
	// if (cub->ray_c.nbr_sprite != 0)
	// 	for (int i = 0;i < cub->ray_c.nbr_sprite;i++)
	// 		printf("sprite[%d] = x :%f, y :%f\n", i, cub->ray_c.sprite[i -1].pos.x, cub->ray_c.sprite[i -1].pos.y);
	return (1);
}
