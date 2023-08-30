# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 17:46:30 by mlagrini          #+#    #+#              #
#    Updated: 2023/08/30 14:05:09 by mlagrini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	main.c map_parser/parse1.c \
				map_parser/utils.c map_parser/cub_parse.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS		=	${SRC:.c=.o}
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -Ofast
LIBS		=	~/Desktop/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT		=	libft/libft.a
RM			=	rm -rf
NAME		=	cub3d

all:	${NAME} ${LIBFT}

%.o:%.c
		${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
		make -C libft

${NAME}: ${OBJS} ${LIBFT}
		${CC} ${CFLAGS} ${LIBS} ${OBJS} ${LIBFT} -o ${NAME}
		clear

clean:
		cd libft && make clean
		${RM} ${OBJS}

fclean: clean
		cd libft && make fclean
		${RM} ${NAME}
		clear
		
re: fclean all

.PHONY: all clean fclean re