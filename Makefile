# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 14:04:02 by jodufour          #+#    #+#              #
#    Updated: 2021/06/22 20:48:42 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

######################################
#              COMMANDS              #
######################################
CC			=	gcc -c -o
LINKER		=	gcc -o
RM			=	rm -rf
MAKEDIR		=	mkdir -p

#####################################
#            DIRECTORIES            #
#####################################
MLXD		=	mlx/
GNL_SRCD	=	get_next_line/
SRCD		=	srcs/
OBJD		=	objs/

INCLUDE		=	\
				includes		\
				${MLXD}

#####################################
#             LIBRARIES             #
#####################################
MLXA		=	libmlx.a
MLXA		:=	${addprefix ${MLXD}, ${MLXA}}
MLX			=	mlx

######################################
#            SOURCE FILES            #
######################################
GNL_SRCS	=	\
				get_next_line.c			\
				get_next_line_utils.c

SRCS		=	\
				${GNL_SRCS}			\
				main.c				\
				sl_free.c			\
				sl_strlen.c			\
				sl_strjoin.c		\
				sl_get_lst.c		\
				sl_get_map.c		\
				sl_run_game.c		\
				sl_init_game.c		\
				sl_errno_msg.c		\
				sl_check_map.c		\
				sl_print_map.c		\
				sl_multifree.c		\
				sl_lstadd_back.c

######################################
#            OBJECT FILES            #
######################################
OBJS		=	${SRCS:.c=.o}
OBJS		:=	${addprefix ${OBJD}, ${OBJS}}

DEPS		=	${OBJS:.o=.d}

#####################################
#               FLAGS               #
#####################################
CFLAGS		=	-Wall -Wextra -MMD -I${INCLUDE} -framework OpenGL -framework AppKit
LDFLAGS		=	-L${MLXD} -l${MLX}

ifeq (${DEBUG}, true)
	CFLAGS	+=	-g
endif

${NAME}:	${OBJS} ${MLXA}
	${LINKER} $@ ${LDFLAGS} ${OBJS}

all:	${NAME}

-include ${DEPS}

${OBJD}%.o:	${SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${OBJD}%.o:	${GNL_SRCD}%.c
	@${MAKEDIR} ${OBJD}
	${CC} $@ ${CFLAGS} $<

${MLXA}:
	${MAKE} -C ${dir $@}

clean:
	${RM} ${OBJD}

fclean:
	${RM} ${OBJD} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
