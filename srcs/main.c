#include "cub3D.h"
static int	check_argv1(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' \
		|| str[i - 4] != '.')
		return (0);
	return (1);
}

static int	check_argv2(t_vars *cub, char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i != 6)
		return (0);
	if (str[i - 1] != 'e' || str[i - 2] != 'v' || str[i - 3] != 'a' \
		|| str[i - 4] != 's' || str[i - 5] != '-' || str[i - 6] != '-')
		return (0);
	cub->save_on = 1;
	return (1);
}

int	cub_loop(t_vars *cub, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	cub->ray_c.mlx = mlx_init();
	if (!cub->ray_c.mlx)
		return (0);
	if (!(get_textures(cub, cub->parsing.textures)))
		return (0);
	cub->ray_c.win = mlx_new_window(cub->ray_c.mlx, cub->parsing.rx, cub->parsing.ry, "cub3D");
	cub->ray_c.img = mlx_new_image(cub->ray_c.mlx, cub->parsing.rx, cub->parsing.ry);
	if (!cub->ray_c.img)
		return(0);
		cub->ray_c.addr = mlx_get_data_addr(cub->ray_c.img, \
		&cub->ray_c.bits_per_pixel, &cub->ray_c.line_length, \
		&cub->ray_c.endian);

	mlx_loop_hook(cub->ray_c.mlx, frame, cub);
	mlx_hook(cub->ray_c.win, 2, 1L<<0, key_press, cub);
	mlx_hook(cub->ray_c.win, 3, 1L<<1, key_release, cub);
	mlx_hook(cub->ray_c.win, 17, 1L<<5, ft_exit, cub);
	cub->ray_c.seconde = time(NULL);
	mlx_loop(cub->ray_c.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	cub;

	if (!(init_parsing(&cub)))
		return (0);
	if (!(parsing(&cub, argv)))
		return (0);
	if (!(init_ray_casting(&cub)))
		return (0);
	init_rays(&cub, cub.parsing.rx, cub.parsing.ry);
	if (!(init_plans(&cub)))
		return (0);
	if ((argc == 2 && check_argv1(argv[1]) == 1)\
		|| (argc == 3 && check_argv2(&cub, argv[2]) == 1))
	{
		if (cub.save_on == 1)
			if (!(init_save_image(&cub)))
				return (0);
		if (!(cub_loop(&cub, argc, argv)))
			return(-1);
	}
	else
		write(1, "\nError : invalid arguments\n", 27);
	return (0);
}