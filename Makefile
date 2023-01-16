# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:00:57 by hleung            #+#    #+#              #
#    Updated: 2023/01/16 17:25:43 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

MLXFLAGS		=	-L mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS			=	-Wall -Werror -Wextra -fsanitize=address -g3

CC				=	gcc

RM				=	rm -rf

SRCS			=	get_next_line.c get_next_line_utils.c so_long.c map.c map_error.c backtrack.c backtrack_utils.c
OBJS			=	${SRCS:.c=.o}
HEADERS			=	includes

%.o:		%.c Makefile
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS} 
			$(MAKE) -C ./mlx
			$(MAKE) -C ./libft
			${CC} $(CFLAGS) libft/libft.a ${OBJS} -o ${NAME}
			
clean:		
			${RM} ${OBJS} a.out

fclean:		clean
			${RM} ${NAME} libft/*.o mlx/*.o libft/libft.a mlx/libmlx.a

re: fclean 
	$(MAKE) all

.PHONY:		all clean fclean re .c.o

#-L mlx -lmlx -framework OpenGL -framework AppKit 