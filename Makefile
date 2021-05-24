# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballet <mballet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:39:52 by mballet           #+#    #+#              #
#    Updated: 2021/05/24 14:19:05 by mballet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXE				=	cub3D

SRCS			=	srcs/main.c \
					srcs/utils.c \
					srcs/utils2.c \
					srcs/ft_exit.c \
					srcs/init/init_parsing.c \
					srcs/init/init_ray_casting.c \
					srcs/init/init_ray_c_rays.c \
					srcs/init/init_ray_c_matrix.c \
					srcs/init/init_plans.c \
					srcs/init/init_rays.c \
					srcs/init/init_sprite.c \
					srcs/init/init_save_image.c \
					srcs/ray_casting/frame.c \
					srcs/ray_casting/rotation.c \
					srcs/ray_casting/graphical_loop.c \
					srcs/ray_casting/display.c \
					srcs/ray_casting/check_ns.c \
					srcs/ray_casting/check_ew.c \
					srcs/ray_casting/check_fc.c \
					srcs/ray_casting/keypress.c \
					srcs/ray_casting/sprite.c \
					srcs/ray_casting/create_plans_sprite.c \
					srcs/gnl/get_next_line.c \
					srcs/gnl/get_next_line_utils.c \
					srcs/parsing/parsing.c \
					srcs/parsing/utils.c \
					srcs/parsing/utils2.c \
					srcs/parsing/utils3.c \
					srcs/parsing/utils4.c \
					srcs/parsing/data/check_data.c \
					srcs/parsing/data/check_res.c \
					srcs/parsing/data/resolution.c \
					srcs/parsing/data/textures/check_path_textures.c \
					srcs/parsing/data/textures/get_textures.c \
					srcs/parsing/map/ft_map.c \
					srcs/parsing/map/check_world_map.c \
					srcs/parsing/map/get_world_map.c \
					srcs/save_image/save_image.c \

OBJS			=	$(SRCS:.c=.o)

HEADERS			=	includes/cub3D.h \
					mlx/mlx.h \
					includes/get_next_line.h \

CC				=	gcc

CFLAGS			=	-g -Wall -Wextra -Werror -Iincludes/ -Imlx/

SANFLAGS		=	-g3 -fsanitize=address

FILEMLX			=	mlx/minilibx_mms_20200219

MLX				=	libmlx.dylib

RM				=	/bin/rm -f

all:		$(EXE)

$(EXE):		$(MLX) $(OBJS)
				@$(CC) -o $@ $^

%.o :		%.c $(HEADERS)
				@$(CC) $(CFLAGS) -o $@ -c $<

$(MLX):
				@$(MAKE) -C$(FILEMLX) -s
				@mv $(FILEMLX)/$(MLX) .

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(MLX)
				$(RM) $(EXE)

re:			fclean all

.PHONY:		clean fclean all re

# $(MAKE) -Cmlx pour dire fait un make dans ce dossier
# @ au debut pour le faire en silence (pas d'affichage sur fd 1)