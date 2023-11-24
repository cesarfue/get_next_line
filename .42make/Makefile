# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 18:46:17 by cefuente          #+#    #+#              #
#    Updated: 2023/11/23 19:32:02 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_numbers.c \
	ft_strings.c \
	ft_switch.c \
	ft_printf.c 

BNS = 

OBJS    =    ${SRCS:.c=.o}

B_OBJS    =    ${BNS:.c=.o}

HEADER    =    includes/ft_printf.h

NAME    =    libftprintf.a

CC        =    cc

AR        =    ar -rc

FLAGS    =    -Wall -Wextra -Werror

all        :    ${NAME}

%.o        :    %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}    :    ${OBJS} Makefile
	${AR} ${NAME} ${OBJS}

bonus    :
	@make SRCS="${SRCS} ${BNS}"

clean    :
	rm -f ${OBJS} ${B_OBJS}

fclean    :    clean
	rm -f ${NAME} ${B_OBJS}

re        :    fclean all

.PHONY    :    all clean fclean re bonus
