#include "cub3D.h"

static int	check_args(t_vars *cub, int argc, char **argv)
{
	int	i;

	if (argc != 2 && argc != 3)
		return (0);
	if (argc == 2)
	{
		i = ft_strlen(argv[1]);
		if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u' \
				|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
			return (0);
	}
	else if (argc == 3)
	{
		i = ft_strlen(argv[2]);
		if (i != 6 || argv[2][i - 1] != 'e' || argv[2][i - 2] != 'v' \
				|| argv[2][i - 3] != 'a' || argv[2][i - 4] != 's' \
				|| argv[2][i - 5] != '-' || argv[2][i - 6] != '-')
			return (0);
		cub->save_on = 1;
	}
	return (1);
}

static int	save(t_vars *cub)
{
	cub->ray_c.free_win = 1;
	if (!(init_save_image(cub)))
		return (0);
	save_header(cub);
	if (!(create_plans_sprite(cub)))
	{
		if (close(cub->fd) == -1)
			write(1, "\nClose did not work\n", 20);
		return (0);
	}
	if (!(multithread(cub)))
	{
		if (close(cub->fd) == -1)
			write(1, "\nClose did not work\n", 20);
		return (0);
	}
	save_bitmap(cub);
	if (close(cub->fd) == -1)
		write(1, "\nClose did not work\n", 20);
	ft_exit(cub);
	return (1);
}

int	cub_loop(t_vars *cub)
{
	cub->ray_c.mlx = mlx_init();
	if (!cub->ray_c.mlx)
		return (0);
	if (!(get_textures(cub, cub->parsing.textures)))
		return (0);
	cub->ray_c.win = mlx_new_window(cub->ray_c.mlx, cub->parsing.old_rx, \
						cub->parsing.old_ry, "cub3D");
	if (!cub->ray_c.win)
		return (0);
	cub->ray_c.img = mlx_new_image(cub->ray_c.mlx, cub->parsing.old_rx, \
						cub->parsing.old_ry);
	if (!cub->ray_c.img)
		return (0);
	cub->ray_c.addr = mlx_get_data_addr(cub->ray_c.img, \
		&cub->ray_c.bits_per_pixel, &cub->ray_c.line_length, \
		&cub->ray_c.endian);
	if (cub->save_on == 1 && !(save(cub)))
		return (0);
	mlx_loop_hook(cub->ray_c.mlx, frame, cub);
	mlx_hook(cub->ray_c.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->ray_c.win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->ray_c.win, 17, 1L << 5, exit_red_cross, cub);
	mlx_loop(cub->ray_c.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	cub;

	init_parsing(&cub);
	if (check_args(&cub, argc, argv) == 1)
	{
		if (!(parsing(&cub, argv)) || !(init_ray_casting(&cub)))
		{
			ft_exit(&cub);
			return (-1);
		}
	}
	else
	{
		write(1, "\nError : invalid arguments\n", 27);
		return (-1);
	}
	init_rays(&cub, cub.parsing.rx, cub.parsing.ry, &cub.ray_c);
	if (!(init_plans(&cub)) || !(cub_loop(&cub)))
	{
		ft_exit(&cub);
		return (-1);
	}
	return (0);
}
