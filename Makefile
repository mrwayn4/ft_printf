# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouram <ibouram@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 10:58:09 by ibouram           #+#    #+#              #
#    Updated: 2023/12/08 11:50:24 by ibouram          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RM = rm -f
NAME = libftprintf.a
GFLAGS = -Wall -Wextra -Werror

SRCS = ft_char_str_digit.c ft_printf.c ft_printf_ptr.c ft_printf_hex.c ft_unsint.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} :  ${OBJS}
		ar -rc ${NAME} ${OBJS}

%.o: %.c ft_printf.h
		${CC} ${GFLAGS} -c $< -o $@

clean :
		${RM} ${OBJS}
fclean : clean
		${RM} ${NAME}

re : fclean all