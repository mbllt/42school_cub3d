#include "cub3D.h"

static void	get_v(t_vector *v, t_vars *cub, t_vector sp_pos)
{
	*v = (t_vector){
		.x = sp_pos.x - cub->parsing.px,
		.y = sp_pos.y - cub->parsing.py,
		.z = 0
	};
}

static void	get_v2(t_vector *v2, t_vector v)
{
	t_vector	vbis;

	vbis = (t_vector){
		.x = v.y,
		.y = -v.x,
		.z = 0
	};
	*v2 = normalisation_v(vbis);
}

static void	create_plans(t_sprite sprite, t_plan *plan, int i)
{
	(void)i;
	plan->a = sprite.v.x;
	plan->b = sprite.v.y;
	plan->c = 0;
	plan->d = -sprite.v.x * sprite.pos.x - sprite.v.y * sprite.pos.y;
}

int	create_plans_sprite(t_vars *cub)
{
	int	i;

	i = -1;
	while (++i < cub->ray_c.nbr_sprite)
	{
		get_v(&cub->ray_c.sprite[i].v, cub, cub->ray_c.sprite[i].pos);
		get_v2(&cub->ray_c.sprite[i].v2, cub->ray_c.sprite[i].v);
		create_plans(cub->ray_c.sprite[i], &cub->ray_c.sprite[i].plans, i);
		cub->ray_c.sprite[i].sprite_front = scalaire_v(cub->ray_c.sprite[i].v, \
			cub->ray_c.ray_dir);
	}
	return (1);
}
