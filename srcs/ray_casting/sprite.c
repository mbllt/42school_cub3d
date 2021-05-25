#include "cub3D.h"

static int	intersct_sprite(t_vars *cub, t_vector ray, t_plan plan, \
							t_dot_intersct *intersct)
{
	float		division;

	division = (plan.a * ray.x) + (plan.b * ray.y);
	if (division == 0)
		return (0);
	(*intersct).t_distance = - ((plan.a * cub->parsing.px) \
							+ (plan.b * cub->parsing.py) + plan.d);
	(*intersct).t_distance /= division;
	if ((*intersct).t_distance < 0)
		return (0);
	intersct_dot(cub, ray, intersct);
	return (1);
}

t_dot_intersct	compare_sprite(t_vars *cub, t_dot_intersct *sprite, \
		float *r_temp, float *r)
{
	t_dot_intersct	temp;
	int				i;

	temp.dot = (t_vector){0, 0, 0};
	temp.t_distance = -1;
	temp.cardinal = -1;
	i = 0;
	while (i < cub->ray_c.nbr_sprite)
	{
		if (sprite[i].t_distance >= 0 && (temp.t_distance == -1 \
			|| sprite[i].t_distance < temp.t_distance))
		{
			temp.t_distance = sprite[i].t_distance;
			temp.dot.x = sprite[i].dot.x;
			temp.dot.y = sprite[i].dot.y;
			temp.dot.z = sprite[i].dot.z;
			temp.cardinal = 6;
			*r = r_temp[i];
		}
		i++;
	}
	return (temp);
}

static int	check_trans(t_vars *cub, t_dot_intersct intersct, float r)
{
	unsigned int	pixel;
	t_index			index;

	index.x = 0;
	index.y = 0;
	get_xy_sprite(intersct, cub->parsing.textures[6], &index, r);
	pixel = get_pixel(cub->parsing.textures[6], index.x, index.y);
	if ((pixel >> 24) > 0)
		return (0);
	return (1);
}

static void	fill_sprite(t_dot_intersct *sprite, float *r_temp, \
		t_dot_intersct intersct, float r)
{
	*r_temp = r;
	sprite->dot.x = intersct.dot.x;
	sprite->dot.y = intersct.dot.y;
	sprite->dot.z = intersct.dot.z;
	sprite->t_distance = intersct.t_distance;
	sprite->ray = intersct.ray;
}

t_dot_intersct	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct, \
						float *r)
{
	int				i;
	t_dot_intersct	*sprite;
	float			*r_temp;
	t_dot_intersct	temp;

	if (!(malloc_sp_r_temp(cub, &sprite, &r_temp)))
		return ((t_dot_intersct){(t_vector){0, 0, 0}, 0, -10, \
			(t_vector){0, 0, 0}});
	init(cub, sprite, r_temp);
	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
	{
		if (cub->ray_c.sprite[i].sprite_front >= 0 && intersct_sprite \
			(cub, ray, cub->ray_c.sprite[i].plans, intersct) == 1)
		{
			*r = get_r(cub, intersct, i);
			if ((*intersct).dot.z < 1 && (*intersct).dot.z >= 0 \
				&& *r >= 0 && *r < 1 && check_trans(cub, *intersct, *r) == 1)
				fill_sprite(&sprite[i], &r_temp[i], *intersct, *r);
		}
	}
	temp = compare_sprite(cub, sprite, r_temp, r);
	free_sp_r_temp(&sprite, &r_temp);
	return (temp);
}
