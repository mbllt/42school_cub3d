#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <get_next_line.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <pthread.h>
# include <limits.h>

#define BLACK	0x00000000
#define TEAL	0x00008080
#define BLUE	0x0000BFFF
#define BROWN	0x00FFDEAD
#define GREEN	0x0000FF00
#define ORANGE	0x00FFA500
#define PINK	0x00DB7093
#define GREY	0x00808080

typedef enum e_dir
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	F,
	C,
	SPRITE,
}t_dir;

typedef	struct s_direction
{
	float	t_north;
	float	t_south;
	float	t_east;
	float	t_west;
}t_direction;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}t_vector;

typedef struct s_dot_intersct
{
	t_vector	dot;
	float		t_distance;
	int			cardinal;
	t_vector	ray;
}t_dot_intersct;

typedef struct s_plan
{
	float	a;
	float	b;
	float	c;
	float	d;
}t_plan;

typedef struct s_key
{
	int	right;
	int	left;
	int	forward;
	int	backward;
	int	down;
	int	up;
	int	rot_x_right;
	int	rot_x_left;
	int	rot_z_right;
	int	rot_z_left;
	int	exit;
}t_key;

typedef struct s_text
{
	int		width;
	int		height;
	void	*mlx;
	void	*img;
	unsigned int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_text;

typedef struct s_sprite
{
	t_plan		plans;
	t_vector	pos;
	t_vector	v;
	t_vector	v2;
	float		sprite_front;
}t_sprite;


typedef	struct s_ray
{
	float		fov;
	float		ratio_horizon;
	float		ratio_vertical;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_vector	rays;
	t_vector	**stock_rays;
	float		distance;
	t_vector	xyz;
	uintptr_t	color;
	t_plan		**plans;
	float		rota_x;
	float		rota_z;
	float		**matrix_x;
	float		**matrix_z;
	t_key		key;
	int			fps;
	int			seconde;
	char		*cos;
	char		*sin;
	char		*pixel_color;
	int			nbr_sprite;
	t_sprite	*sprite;
	t_vector	ray_dir;
}				t_ray;

typedef struct s_parsing
{
	int			rx;
	int			ry;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	unsigned int	ff;
	unsigned int	cc;
	int			nbr_param;
	int			map_x;
	int			map_y;
	char		**world_map;
	t_vector	pos;
	float		px;
	float		py;
	float		pz;
	char		cardinal;
	t_text		textures[7];
	char 		**file;
	int			file_y;
}t_parsing;

typedef struct s_vars
{
	t_ray		ray_c;
	t_parsing	parsing;
}t_vars;

typedef struct s_thread
{
	t_vars	cub;
	int		thread_num;
}t_thread;

int				init_parsing(t_vars *cub);
int				init_ray_casting(t_vars *cub);
void			init_vars_rays(t_vars *cub);
int				init_stock_rays(t_vars *cub, int width, int height);
void			init_rays(t_vars *cub, int width, int height);
int				init_plans(t_vars *cub);
int				init_matrix_x(t_vars *cub);
int				init_matrix_z(t_vars *cub);
void			my_mlx_pixel_put(t_vars *mlx, int x, int y, unsigned int color);
int				ft_exit(t_vars *cub);
int				key_press(int key, t_vars *cub);
int				key_release(int key, t_vars *cub);
int				frame(t_vars *cub);
void			*graphical_loop(void *thread_data);
//int				graphical_loop(t_vars *cub);
t_vector		rotation_x(t_vars *cub, t_vector ray);
t_vector		rotation_z(t_vars *cub, t_vector ray);
void			display(t_vars *cub, int i, int j, t_dot_intersct prio_wall, float r);
int				cub_loop(t_vars *cub, int argc, char **argv);
int				parsing(t_vars *cub, char **argv);
int				check_data(t_vars *cub, char *line, int ret);
char			*ft_realloc(char *str, size_t size);
int				ft_atoi(const char *str);
int				check_get_res(t_vars *cub, char **str, int size);
int				get_number(char *line, int *i, int nbr);
int				check_colors(t_vars *cub, char **str, int size);
int				check_if_not_digit(char *str);
int				get_path_nsew(t_vars *cub, char *line, int *i, int nbr_path);
char			*stock_file(char *line);
int				map(t_vars *cub, char **map);
int				is_param(char c);
void			ft_double_free(char **str, int size);
size_t			ft_strlcpy(char *dest, const char *src, size_t destsize);
int				get_world_map(t_vars *cub, char **map, int map_y, int file_y);
int				check_world_map(t_vars *cub, char **world_map);
int				ft_map(t_vars *cub, char **map, int file_y);
int				is_cardinal(char c);
int				is_one(char c);
int				is_pos(int nbr);
int				size_colors(int nbr);
int				check_res_color(t_vars *cub, char *line);
int				check_path_textures(t_vars *cub, char *line);
char			*ft_substr(char *s, int start, size_t len);
int				check_map(t_vars *cub, char **map);
int				is_path_textures(char *line);
int				is_res_or_colors(char *line);
char			**ft_split(char *s, char c, int *size);
char			*ft_substr2(char *s, int start);
int				check_nbr_coma(char *str);
t_plan			*find_walls_n(t_vars *cub, int size);
t_plan			*find_walls_s(t_vars *cub, int size);
t_plan			*find_walls_e(t_vars *cub, int size);
t_plan			*find_walls_w(t_vars *cub, int size);
t_dot_intersct	check_wall_n(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_wall_s(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_wall_e(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_wall_w(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_wall_f(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_wall_c(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
void			intersct_dot(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
void			move(t_vars *cub);
void			rotate(t_vars *cub);
int				get_textures(t_vars *cub, t_text *textures);
unsigned int	create_trgb(int t, int r, int g, int b);
int				init_sprite(t_vars *cub, char **world_map);
t_dot_intersct	sprite(t_vars *cub, t_vector ray, t_dot_intersct *intersct, float *r);
t_dot_intersct	check_sprite_n(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_sprite_s(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_sprite_e(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_dot_intersct	check_sprite_w(t_vars *cub, t_vector ray, t_dot_intersct *intersct);
t_vector		normalisation_v(t_vector v);
float			norm_v(t_vector v);
int				multithread(t_vars *cub);
int				create_plans_sprite(t_vars *cub);
unsigned int	get_pixel(t_text texture, int x, int y);
float			scalaire_v(t_vector v, t_vector v2);
void			get_xy_sprite(t_dot_intersct prio_wall, t_text text, int *x, int *y, float r);

#endif