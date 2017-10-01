NAME = lem-in
CC = gcc
SRC =	main.c					\
		ants.c					\
		parsing.c				\
		check.c					\
		display.c				\
		tools.c					\
		room.c					\
		file.c					\
		free.c					\
		is.c					\
		error.c					\
		precheck.c				\
		link.c					\
		integrity.c				\
		init.c					\
		free_pars.c				\
		move.c					\
		path_check.c			\
		path_clean.c			\
		path_create.c			\
		pathfinding.c			\
		node.c					\
		tree.c

INC = -I includes -I libft/includes
SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) -g $(OBJ) $(INC) libft/libft.a -o $(NAME)

%.o : srcs/%.c
	$(CC) -g -c $< $(FLAGS) $(INC) -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
