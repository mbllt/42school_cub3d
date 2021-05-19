#include "cub3D.h"

static void	create_plans(t_vars *cub, t_plan *plan, t_sprite sprite)
{
	t_vector	normal;

	normal.x = (cub->ray_c.sprite->pos.x + 0.5) - cub->parsing.px;
	normal.y = (cub->ray_c.sprite->pos.y + 0.5) - cub->parsing.py;
	normal.z = 0;
	(*plan).a = normal.x;
	(*plan).b = normal.y;
	(*plan).c = normal.z;
	(*plan).d = - (normal.x * (cub->ray_c.sprite->pos.x + 0.5)) \
				- (normal.y * (cub->ray_c.sprite->pos.y + 0.5)) \
				- (normal.z * cub->ray_c.sprite->pos.z);
}

static int	create_plans_sprite(t_vars *cub, t_plan **plan)
{
	int	i;

	(*plan) = malloc(sizeof(t_plan) * cub->ray_c.nbr_sprite);
	if (!(*plan))
		return (0);
	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
		create_plans(cub, plan[i], cub->ray_c.sprite[i]);
	return (1);
}

static t_dot_intersct	compare_t(t_dot_intersct *intersct)
{}

t_dot_intersct	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct)
{
	t_plan			*plan;
	t_dot_intersct	intersct[4];
	t_dot_intersct	prio;

	if (!(create_plans_sprite(cub, &plan)))
		return ((t_dot_intersct){(t_vector){0,0,0},0,0});
	if (ray.y < 0)
	{	
		intersct[0] = check_sprite(cub, ray, &intersct[0]);
	}
	if (ray.y > 0)
	{
		intersct[1] = chech_sprite(cub, ray, &intersct[1]);
	}
	if (ray.x > 0)
	{
		intersct[2] = chech_sprite(cub, ray, &intersct[2]);
	}
	if (ray.x < 0)
	{
		intersct[3] = chech_sprite(cub, ray, &intersct[3]);
	}
	prio = compare_t(intersct);

}