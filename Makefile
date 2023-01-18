# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:00:57 by hleung            #+#    #+#              #
#    Updated: 2023/01/18 13:08:09 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

MLXFLAGS		=	-L mlx -lmlx -framework OpenGL -framework Appkit

PFFLAGS			=	-L ft_printf -lftprintf

LIBFTFLAGS		=	-L libft -lft

CFLAGS			=	-Wall -Werror -Wextra

CC				=	gcc

RM				=	rm -rf

SRCS			=	srcs/backtrack_utils.c srcs/backtrack.c srcs/events.c srcs/free.c srcs/get_next_line_utils.c \
					srcs/get_next_line.c srcs/map_error.c srcs/map.c srcs/move.c srcs/render.c srcs/so_long.c
					
OBJS			=	${SRCS:.c=.o}

HEADERS			=	includes

%.o:		%.c Makefile ./mlx/*.c ./libft/*.c ./ft_printf/*.c
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS} 
			$(MAKE) -C ./mlx
			$(MAKE) -C ./libft
			$(MAKE) -C ./ft_printf
			${CC} $(CFLAGS) $(MLXFLAGS) ${PFFLAGS} ${LIBFTFLAGS} ${OBJS} -o ${NAME}
			
clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} libft/*.o mlx/*.o ft_printf/*.o libft/libft.a mlx/libmlx.a ft_printf/libftprintf.a

re:			fclean 
			$(MAKE) all

.PHONY:		all clean fclean re .c.o
