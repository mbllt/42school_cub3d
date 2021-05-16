#include "cub3D.h"

int	cub_start(t_vars *cub, int argc, char **argv)
{
	if (!(parsing(cub, argv)))
		return (0);
	if (!(init_ray_casting(cub)))
		return (0);
	(void)argc;
	(void)argv;
	init_rays(cub, cub->parsing.rx, cub->parsing.ry);
	if (!(init_plans(cub)))
		return (0);
	cub->ray_c.mlx = mlx_init();
	if (!cub->ray_c.mlx)
		return (0);
	cub->ray_c.win = mlx_new_window(cub->ray_c.mlx, cub->parsing.rx, cub->parsing.ry, "cub3D");
	cub->ray_c.img = mlx_new_image(cub->ray_c.mlx, cub->parsing.rx, cub->parsing.ry);
	if (!cub->ray_c.img)
		return(0);
	cub->ray_c.addr = mlx_get_data_addr(cub->ray_c.img, &cub->ray_c.bits_per_pixel, &cub->ray_c.line_length, &cub->ray_c.endian);
	mlx_hook(cub->ray_c.win, 2, 1L<<0, key_press, cub);
	mlx_hook(cub->ray_c.win, 3, 1L<<1, key_release, cub);
	mlx_loop_hook(cub->ray_c.mlx, frame, cub);
	cub->ray_c.seconde = time(NULL);
	//cub->ray_c.fps = 0;
	mlx_loop(cub->ray_c.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	cub;

	if (!(init_parsing(&cub)))
		return (0);
	if (argc == 2/* || (argc == 3 && save(argc, argv) */)
	{
		if (!(cub_start(&cub, argc, argv)))
			return(-1);
	}
	else
		write(1, "\nInvalid arguments\n", 19);
	return (0);
}