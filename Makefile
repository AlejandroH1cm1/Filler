FILES_C = src/main.c src/utils.c src/map.c src/utils2.c src/utils3.c src/pos.c src/direction.c src/piece.c src/subs.c
FILES_O = main.o map.o utils.o pos.o utils2.o utils3.o direction.o piece.o subs.o
NAME = aherrera.filler
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@cp libft/libft.a ./
	@gcc -c $(FLAGS) $(FILES_C) -I libft/includes
	@gcc -o $(NAME) $(FLAGS) $(FILES_O) -I libft/includes -L . -lft

clean:
	@/bin/rm -f $(FILES_O) $(FILES_O)
	@make -C libft/ clean

fclean: clean 
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make -C libft/ fclean

re:	fclean all

test:
	@sh ./resources/run2.sh resources

retest: re clean test
