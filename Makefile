# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 17:46:30 by mlagrini          #+#    #+#              #
#    Updated: 2023/09/29 19:53:46 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	src/main.c src/movement/player_direction.c src/cub_init.c src/cub_bottons.c \
				src/map_parser/cub_parse.c src/map_parser/utils.c \
				src/map_parser/cub_parse2.c src/map_parser/cub_parse3.c \
				src/map_parser/cub_parse4.c src/map_parser/cub_parse5.c \
				src/map_parser/cub_parse6.c src/map_parser/cub_free.c \
				libs/gnl/get_next_line.c libs/gnl/get_next_line_utils.c \
				src/cub_draw.c src/cub_newdraw.c src/cub_rays.c \
				src/projection.c src/cub_texture.c src/cub_buttons_utils.c \
				src/cub_rays_utils.c src/cub_rays_utils2.c
OBJS		=	${SRC:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror #-O3 -Ofast -flto#-g -fsanitize=address
LIBS		=	~/Desktop/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT		=	libs/libft/libft.a
RM			=	rm -rf
NAME		=	cub3D
INCLUDES	=	includes/cub3d.h

all:	${NAME} ${LIBFT}

%.o:%.c $(INCLUDES)
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: 
		make -C libs/libft

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${LIBS} ${OBJS} ${LIBFT} -o ${NAME}
		clear

clean:
		cd libs/libft && make clean
		${RM} ${OBJS}

fclean: clean
		cd libs/libft && make fclean
		${RM} ${NAME}
		clear
		
re: fclean all

.PHONY: all clean fclean re