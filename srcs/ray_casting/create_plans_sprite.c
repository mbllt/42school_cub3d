#include "cub3D.h"

static void	create_plans(t_vector pos_sprite, t_vars *cub, t_plan *plan, t_vector *v)
{
	v->x = pos_sprite.x - cub->parsing.px;
	v->y = pos_sprite.y - cub->parsing.py;
	v->z = 0;
	plan->a = v->x;
	plan->b = v->y;
	plan->c = 0;
	plan->d = - v->x * pos_sprite.x - v->y * pos_sprite.y;
	//printf("%fx+%fy+%fz+%f=0 | ", plan->a, plan->b, plan->c, plan->d);
	//printf("(%f,%f,%f) | ", pos_sprite.x, pos_sprite.y, pos_sprite.z);
	//printf("(%f,%f,%f)\n\n", cub->parsing.px, cub->parsing.py, cub->parsing.pz);
}

int	create_plans_sprite(t_vars *cub, t_plan **plan, t_vector *v)
{
	int	i;

	(*plan) = malloc(sizeof(t_plan) * cub->ray_c.nbr_sprite);
	if (!(*plan))
		return (0);
	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
	{
		create_plans(cub->ray_c.sprite_p[i], cub, &(*plan)[i], v);
		//printf("plan[%d] : a = %f && b = %f && c = %f && d = %f\n\n", i, (*plan)[i].a, (*plan)[i].b, (*plan)[i].c, (*plan)[i].d);
	}
	//printf("%f\n", (*plan)[2].d);
	return (1);
}