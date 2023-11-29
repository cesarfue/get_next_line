# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/11/28 20:57:01 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
	get_next_line_utils.c \
	main.c \

OBJS    =    ${SRCS:.c=.o}

OBJS	:= $(addprefix build/, $(OBJS))

HEADER    =    get_next_line.h

NAME    =    a.out

CC        =    cc

FLAGS    =    -Wall -Wextra -Werror -I includes -g -D BUFFER_SIZE=1000000

all        :    ${NAME}

build/%.o        :    %.c ${HEADER} | build
	${CC} ${FLAGS} -c $< -o $@

${NAME}    :    ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${B_OBJS}

bonus    :
	@make SRCS="${SRCS} ${BNS}"

build:
	mkdir -p build

clean    :
	rm -f ${OBJS} ${B_OBJS}

fclean    :    clean
	rm -f ${NAME} ${B_OBJS}

re        :    fclean all

.PHONY    :    all clean fclean re bonus
