# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 14:44:54 by cpapot            #+#    #+#              #
#    Updated: 2022/11/30 14:25:37 by cpapot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../../libftprintf.a

SRC_ROOT =	ft_printf.c

SRCS	=	ft_putunsint_len.c ft_putstr_len.c \
			ft_putpercent_len.c ft_putnull_len.c ft_putint_len.c \
			ft_puthexavoid_len.c ft_puthexamin_len.c ft_puthexamaj_len.c \
			ft_putchar_len.c ft_findformat.c

SRCS_LIBFT	= ft_bzero.c ft_itoa.c ft_strlen.c ft_substr.c

SRC_DIR = $(addprefix printf_utils/, $(SRCS))

LIBFT_DIR = $(addprefix libft_utils/, $(SRCS_LIBFT))

HEADERS = ft_printf.h

CFLAGS = -Wall -Wextra -Werror

OBJS	= $(SRC_ROOT:.c=.o) ${SRC_DIR:.c=.o} ${LIBFT_DIR:.c=.o}

%.o:	%.c ${HEADERS} Makefile
	$(CC) -I ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

.PHONY : re all clean fclean
