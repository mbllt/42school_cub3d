#include "cub3D.h"

static void	get_v(t_vector *v, t_vars *cub, t_vector sp_pos)
{
	*v = (t_vector) {
		.x = sp_pos.x - cub->parsing.px,
		.y = sp_pos.y - cub->parsing.py,
		.z = sp_pos.z - cub->parsing.pz
	};
}

static void	get_v2(t_vector *v2, t_vector v)
{
	*v2 = (t_vector){
		.x = v.y,
		.y = - v.x,
		.z  = 0
	};
	*v2 = normalisation_v(*v2);
}

static void	create_plans(t_sprite sprite, t_plan *plan)
{
	plan->a = sprite.v.x;
	plan->b = sprite.v.y;
	plan->c = sprite.v.z;
	plan->d = - sprite.v.x * sprite.pos.x - sprite.v.y * sprite.pos.y;
	//printf("%fx+%fy+%fz+%f=0 | ", plan->a, plan->b, plan->c, plan->d);
	//printf("(%f,%f,%f) | ", pos_sprite.x, pos_sprite.y, pos_sprite.z);
	//printf("(%f,%f,%f)\n\n", cub->parsing.px, cub->parsing.py, cub->parsing.pz);
}

int	create_plans_sprite(t_vars *cub)
{
	int	i;

	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
	{
		get_v(&cub->ray_c.sprite[i].v, cub, cub->ray_c.sprite[i].pos);
		get_v2(&cub->ray_c.sprite[i].v2, cub->ray_c.sprite[i].v);
		create_plans(cub->ray_c.sprite[i], &cub->ray_c.sprite[i].plans);
		//printf("plan[%d] : a = %f && b = %f && c = %f && d = %f\n\n", i, (*plan)[i].a, (*plan)[i].b, (*plan)[i].c, (*plan)[i].d);
	}
	//printf("%f\n", (*plan)[2].d);
	return (1);
}