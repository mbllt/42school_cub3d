# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballet <mballet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 14:39:52 by mballet           #+#    #+#              #
#    Updated: 2021/05/27 18:01:34 by mballet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

EXE				=	cub3D

SRCS_FILES			=	main.c \
					utils.c \
					utils2.c \
					utils3.c \
					utils4.c \
					ft_exit.c \
					init/init_parsing.c \
					init/init_ray_casting.c \
					init/init_ray_c_rays.c \
					init/init_ray_c_matrix.c \
					init/init_plans.c \
					init/init_rays.c \
					init/init_sprite.c \
					init/init_save_image.c \
					ray_casting/frame.c \
					ray_casting/rotation.c \
					ray_casting/graphical_loop.c \
					ray_casting/display.c \
					ray_casting/check_ns.c \
					ray_casting/check_ew.c \
					ray_casting/check_fc.c \
					ray_casting/keypress.c \
					ray_casting/sprite.c \
					ray_casting/create_plans_sprite.c \
					ray_casting/get_xy_dir_ns.c \
					ray_casting/get_xy_dir_ew.c \
					ray_casting/get_xy_dir_fc.c \
					ray_casting/get_xy_sprite.c \
					gnl/get_next_line.c \
					gnl/get_next_line_utils.c \
					parsing/parsing.c \
					parsing/utils.c \
					parsing/utils2.c \
					parsing/utils3.c \
					parsing/utils4.c \
					parsing/utils5.c \
					parsing/data/check_data.c \
					parsing/data/check_res.c \
					parsing/data/resolution.c \
					parsing/data/colors.c \
					parsing/data/textures/check_path_textures.c \
					parsing/data/textures/get_textures.c \
					parsing/map/ft_map.c \
					parsing/map/check_world_map.c \
					parsing/map/get_world_map.c \
					save_image/save_image.c \

OBJS_DIR		=	.objs

PATHS_OBJS		=	.objs/init	\
					.objs/ray_casting	\
					.objs/gnl	\
					.objs/parsing	\
					.objs/parsing/data	\
					.objs/parsing/data/textures	\
					.objs/parsing/map	\
					.objs/save_image	\

OBJS_MAIN		=	$(OBJS_DIR) $(PATHS_OBJS)

SRCS_DIR		=	srcs

OBJS			=	$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))

SRCS			=	$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

HEADERS			=	includes/cub3D.h \
					mlx/mlx.h \
					includes/get_next_line.h

CC				=	gcc

CFLAGS			=	-g -Wall -Wextra -Werror -Iincludes/ -Imlx/

SANFLAGS		=	-g3 -fsanitize=address

FILEMLX			=	mlx/minilibx_mms_20200219

MLX				=	libmlx.dylib

RM				=	/bin/rm -f

green			= \033[32m

all:		$(EXE)

$(OBJS_MAIN):
				@mkdir -p $(OBJS_DIR)
				@mkdir -p $(PATHS_OBJS)

$(EXE):		$(MLX) $(OBJS)
				@$(CC) -o $@ $^
				@echo "      $(green)Cub lancé !"

$(MLX):
				@$(MAKE) -C$(FILEMLX) -s
				@mv $(FILEMLX)/$(MLX) .

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c $(HEADERS)
				@$(CC) $(CFLAGS) -o $@ -c $<

clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(MLX)
				@$(RM) $(EXE)

re:			fclean all

.PHONY:		clean fclean all re

# $(MAKE) -Cmlx pour dire fait un make dans ce dossier
# @ au debut pour le faire en silence (pas d'affichage sur fd 1)