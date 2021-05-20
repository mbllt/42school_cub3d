#include "cub3D.h"

static void	create_plans(t_vars *cub, t_plan *plan, t_vector ray)
{
	cub->ray_c.sprite->v.x = cub->ray_c.sprite->pos.x - cub->parsing.px;
	cub->ray_c.sprite->v.y = cub->ray_c.sprite->pos.y - cub->parsing.py;
	cub->ray_c.sprite->v.z = 0;
	(*plan).a = cub->ray_c.sprite->v.x;
	(*plan).b = cub->ray_c.sprite->v.y;
	(*plan).c = cub->ray_c.sprite->v.z;
	(*plan).d = - (cub->ray_c.sprite->v.x * cub->ray_c.sprite->pos.x) \
				- (cub->ray_c.sprite->v.y * cub->ray_c.sprite->pos.y);
}

static int	create_plans_sprite(t_vars *cub, t_plan **plan, t_vector ray)
{
	int	i;

	(*plan) = malloc(sizeof(t_plan) * cub->ray_c.nbr_sprite);
	if (!(*plan))
		return (0);
	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
		create_plans(cub, &(*plan)[i], ray);
	return (1);
}

static int	intersct_sprite(t_vars *cub, t_vector ray, t_plan plan, t_dot_intersct *intersct)
{
	float	division;

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


int	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct)
{
	t_plan			*plan;
	t_dot_intersct	*temp;
	int				i;

	if (!(create_plans_sprite(cub, &plan, ray)))
		return (0);
	i = -1;
	temp = malloc(sizeof(t_dot_intersct) * cub->ray_c.nbr_sprite);
	if (!temp)
		return (0);
	while (++i < cub->ray_c.nbr_sprite)
		if (!(intersct_sprite(cub, ray, plan[i], &temp[i])))
			continue;
	return (1);
}