#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	libft.h

CHARSRC		=	ft_isalpha.c ft_isdigit.c \
				ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_tolower.c \
				ft_toupper.c

STRINGSRC	=	ft_strmapi.c ft_striteri.c \
				ft_substr.c ft_strlen.c \
				ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c \
				 ft_strnstr.c \
				ft_atoi.c ft_strncmp.c \
				ft_strdup.c ft_strtrim.c \
				ft_split.c ft_itoa.c \
				ft_strjoin.c

MEMSRC		=	ft_memset.c ft_bzero.c \
				ft_memcpy.c ft_memmove.c \
				ft_calloc.c ft_memcmp.c \
				ft_memchr.c

WRITESRC	=	ft_putstr_fd.c ft_putchar_fd.c \
				ft_putnbr_fd.c ft_putendl_fd.c

LSTSRC		=	ft_lstnew.c ft_lstadd_front.c \
				ft_lstadd_back.c ft_lstsize.c \
				ft_lstlast.c ft_lstdelone.c \
				ft_lstiter.c ft_lstclear.c \
				ft_lstmap.c

INTLSTSRC	=	ft_lstintnew.c ft_lstintadd_front.c \
				ft_lstintadd_back.c ft_lstintsize.c \
				ft_lstintlast.c ft_lstintdelone.c \
				ft_lstintiter.c ft_lstintclear.c \
				ft_lstintmap.c

#					Directories

HEADERSDIR	=	includes/

SRCSDIR		=	srcs/

CHARDIR		=	char/

STRINGDIR	=	string/

MEMDIR		=	mem/

WRITEDIR	=	write/

LSTDIR		=	lst/

LSTINTDIR	=	lst_int/

PRINTFDIR	=	ft_printf/

#					Full Path

SRCS		=	$(addprefix $(SRCSDIR)$(CHARDIR),$(CHARSRC)) \
				$(addprefix $(SRCSDIR)$(STRINGDIR),$(STRINGSRC)) \
				$(addprefix $(SRCSDIR)$(MEMDIR),$(MEMSRC)) \
				$(addprefix $(SRCSDIR)$(WRITEDIR),$(WRITESRC)) \
				$(addprefix $(SRCSDIR)$(LSTDIR),$(LSTSRC)) \
				$(addprefix $(SRCSDIR)$(LSTINTDIR),$(INTLSTSRC)) \

PRINTF		=	$(addprefix $(SRCSDIR),$(PRINTFDIR))

HEADER	=	$(addprefix $(HEADERSDIR),$(HEADERS))

OBJS		=	$(SRCS:.c=.o)

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

AR			=	ar rcs

NAME		=	libft.a

CFLAGS		=	-Wall -Wextra -Werror -g3

CC			=	gcc

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

%.o: %.c ${HEADER} Makefile
	$(CC) -I ${CFLAGS} -c $< -o $@

all : ${NAME} printf

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${MAKE} clean -C ${PRINTF}
	${RM} ${OBJS}

fclean:
	${MAKE} clean
	${RM} ${NAME}
	${MAKE} fclean -C ${PRINTF}

re:
	${MAKE} fclean
	${MAKE} all

printf: ${PRINTF}
	${MAKE} -C ${PRINTF}

.PHONY : re all clean fclean printf
