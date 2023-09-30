# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 17:46:30 by mlagrini          #+#    #+#              #
#    Updated: 2023/09/30 09:34:06 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	src/main.c src/movement/player_direction.c src/cub_init.c src/cub_bottons.c \
				src/map_parser/cub_parse.c src/map_parser/utils.c \
				src/map_parser/cub_parse2.c src/map_parser/cub_parse3.c \
				src/map_parser/cub_parse4.c src/map_parser/cub_parse5.c \
				src/map_parser/cub_parse6.c src/map_parser/cub_free.c \
				libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c \
				src/cub_draw.c src/cub_newdraw.c src/cub_rays.c \
				src/cub_texture.c src/cub_buttons_utils.c \
				src/cub_rays_utils.c src/cub_rays_utils2.c
BSRC		=	src/bonus/main_bonus.c src/bonus/movement/player_direction_bonus.c src/bonus/cub_init_bonus.c src/bonus/cub_bottons_bonus.c \
				src/bonus/map_parser/cub_parse_bonus.c src/bonus/map_parser/utils_bonus.c \
				src/bonus/map_parser/cub_parse2_bonus.c src/bonus/map_parser/cub_parse3_bonus.c \
				src/bonus/map_parser/cub_parse4_bonus.c src/bonus/map_parser/cub_parse5_bonus.c \
				src/bonus/map_parser/cub_parse6_bonus.c src/bonus/map_parser/cub_free_bonus.c \
				libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c \
				src/bonus/cub_draw_bonus.c src/bonus/cub_newdraw_bonus.c src/bonus/cub_rays_bonus.c \
				src/bonus/cub_texture_bonus.c src/bonus/cub_buttons_utils_bonus.c \
				src/bonus/cub_rays_utils_bonus.c src/bonus/cub_rays_utils2_bonus.c
OBJS		=	${SRC:.c=.o}
OBJS_BONUS	=	${BSRC:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIBS		=	~/Desktop/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT		=	libs/libft/libft.a
RM			=	rm -rf
NAME		=	cub3D
BNAME		=	cub3D_bonus
INCLUDES	=	includes/cub3d.h

all:	${NAME} ${LIBFT}

bonus:	${BNAME} ${LIBFT}


%.o:%.c $(INCLUDES)
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: 
		make -C libs/libft

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${LIBS} ${OBJS} ${LIBFT} -o ${NAME}
		clear

${BNAME}: ${OBJS_BONUS} ${LIBFT}
		${CC} ${CFLAGS} ${LIBS} ${OBJS_BONUS} ${LIBFT} -o ${BNAME}
		clear

clean:
		cd libs/libft && make clean
		${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
		cd libs/libft && make fclean
		${RM} ${NAME} ${BNAME}
		clear
		
re: fclean all

.PHONY: all clean fclean re bonus