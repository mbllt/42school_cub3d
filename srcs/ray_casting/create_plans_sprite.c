#include "cub3D.h"

static void	create_plans(t_vars *cub, t_plan *plan, t_vector *v)
{
	v->x = cub->ray_c.sprite_p->x - cub->parsing.px;
	v->y = cub->ray_c.sprite_p->y - cub->parsing.py;
	v->z = 0;
	(*plan).a = v->x;
	(*plan).b = v->y;
	(*plan).c = v->z;
	(*plan).d = - (v->x * cub->ray_c.sprite_p->x) \
				- (v->y * cub->ray_c.sprite_p->y);
}

int	create_plans_sprite(t_vars *cub, t_plan **plan, t_vector *v)
{
	int	i;

	(*plan) = malloc(sizeof(t_plan) * cub->ray_c.nbr_sprite);
	if (!(*plan))
		return (0);
	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
		create_plans(cub, &(*plan)[i], v);
	//printf("%f\n", (*plan)[2].d);
	return (1);
}