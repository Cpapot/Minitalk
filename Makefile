#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	minitalk.h

CLIENTFILE	=	client.c check_error.c

SERVERFILE	=	server.c server_utils.c

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

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : ${NAME}

${NAME}:	${CLIENTOBJS} ${SERVEROBJS}
	@${MAKE} lib
	@${MAKE} client
	@${MAKE} server

$(CLIENTOBJSDIR)%.o: ${CLIENTDIR}%.c ${HEAD}
	@$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

$(SERVEROBJSDIR)%.o: ${SERVERDIR}%.c ${HEAD}
	@$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

clean:
	@${MAKE} clean -C ${LIBFTDIR}
	@${RM} ${CLIENTOBJS}
	@${RM} ${SERVEROBJS}
	@echo "\033[00;31m💧 Clean: Removed all the \".o\" files \n\033[00;00m"

fclean:
	@${RM} ${CLIENTOBJS}
	@${RM} ${SERVEROBJS}
	@${RM} server
	@${RM} client
	@${MAKE} fclean -C ${LIBFTDIR}
	@echo  "\033[00;31m🧼 Fclean: Removed the executables \n\033[00;00m"

re:
	${MAKE} fclean
	${MAKE} all

client: ${CLIENTOBJS}
		@${CC} ${CLIENTOBJS} ${LIBFT} -o client
		@echo "\033[00;32m📟 Client ready!\n\033[00m"

server: ${SERVEROBJS}
		@${CC} ${SERVEROBJS} ${LIBFT} -o server
		@echo "\033[00;32m📥 Server ready!\n\033[00m"

lib:
	@${MAKE}	-C ${LIBFTDIR}
	@echo "\033[00;32m✅ Libft ready!\n\033[00m"

.PHONY : re all clean fclean printf lib client server
