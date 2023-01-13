# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:00:57 by hleung            #+#    #+#              #
#    Updated: 2023/01/03 15:45:55 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CFLAGS			=	-Wall -Werror -Wextra 

CC				=	gcc

RM				=	rm -rf

SRCS			=	get_next_line.c get_next_line_utils.c so_long.c map.c render.c
OBJS			=	${SRCS:.c=.o}
HEADERS			=	includes

%.o:		%.c Makefile
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS} 
			${CC} ${OBJS} libmlx.a -framework OpenGL -framework AppKit -o ${NAME}
			
clean:		
			${RM} ${OBJS} a.out

fclean:		clean
			${RM} ${NAME} 

.PHONY:		all clean fclean re .c.o

