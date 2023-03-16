SRC	=	./src/main.c				\
		./src/core.c				\
		./src/argfunc.c				\
		./utils/get_next_line.c		\
		./utils/utils.c				\
		./print/my_printf.c			\
		./print/my_printers.c		\
		./print/flags.c				\
		./print/errors.c			\

OBJ	=	$(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

NAME	=	my_bdd

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc	$(FLAGS) -o	$(NAME)	$(OBJ)

superclean: fclean clean
		rm	-f	*~
		rm	-f	*#
		rm	-f	vgcore*

fclean:	clean
		rm	-f	$(NAME)

clean:
		rm	-f	$(OBJ)

re:	superclean	all