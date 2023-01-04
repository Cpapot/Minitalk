#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	minitalk.h

CLIENTFILE	=	client.c check_error.c

SERVERFILE	=	server.c

LIBFTSRC	=	libftprintf.a libft.a

#					Directories

HEADERSDIR	=	./inc/

SERVERDIR	=	./src/server/

CLIENTDIR	=	./src/client/

LIBFTDIR	=	libft/

SERVEROBJSDIR		=	./objs/server/

CLIENTOBJSDIR		=	./objs/client/

#					Full Path

HEAD		=	$(addprefix $(HEADERSDIR),$(HEADERS))

CLIENT		=	$(addprefix $(CLIENTDIR),$(CLIENTFILE))

SERVER		=	$(addprefix $(SERVERDIR),$(SERVERFILE))

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

CLIENTOBJS	=	$(CLIENT:$(CLIENTDIR)%.c=$(CLIENTOBJSDIR)%.o)

SERVEROBJS	=	$(SERVER:$(SERVERDIR)%.c=$(SERVEROBJSDIR)%.o)

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

NAME		=	minitalk

AR			=	ar rc

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

all : ${NAME}

${NAME}:	Makefile
	${MAKE} lib
	${MAKE} server
	${MAKE} client

$(CLIENTOBJSDIR)%.o: ${CLIENTDIR}%.c ${HEAD}
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

$(SERVEROBJSDIR)%.o: ${SERVERDIR}%.c ${HEAD}
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

clean:
	${MAKE} clean -C ${LIBFTDIR}
	${RM} ${CLIENTOBJS}
	${RM} ${SERVEROBJS}

fclean:
	${RM} ${CLIENTOBJS}
	${RM} ${SERVEROBJS}
	${RM} server
	${RM} client
	${MAKE} fclean -C ${LIBFTDIR}

re:
	${MAKE} fclean
	${MAKE} all

client: ${CLIENTOBJS}
		${CC} ${CLIENTOBJS} ${LIBFT} -o client

server: ${SERVEROBJS}
		${CC} ${SERVEROBJS} ${LIBFT} -o server

lib:
	${MAKE}	-C ${LIBFTDIR}

.PHONY : re all clean fclean printf lib client server
