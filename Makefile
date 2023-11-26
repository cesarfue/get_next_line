# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/11/26 13:43:21 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
	get_next_line_utils.c \

BNS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c

HEADER    =    get_next_line.h

BNS_HEADER = 	get_next_line_bonus.h

OBJS    =    ${SRCS:.c=.o}

B_OBJS    =    ${BNS:.c=.o}

NAME    =    get_next_line.a

CC        =    cc

AR        =    ar -rc

FLAGS    =    -Wall -Wextra -Werror -D BUFFER_SIZE=42

all        :    ${NAME}

%.o        :    %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}    :    ${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

bonus    :
	@make SRCS="${SRCS} ${BNS}" HEADER="${BNS_HEADER}"

clean    :
	rm -f ${OBJS} ${B_OBJS}

fclean    :    clean
	rm -f ${NAME} ${B_OBJS}

re        :    fclean all

.PHONY    :    all clean fclean re bonus
