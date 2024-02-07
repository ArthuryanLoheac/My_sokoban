##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		is_valid_map.c 	\
		print_help.c	\
		generate_map.c	\
		replace_map.c	\
		input_player.c	\
		print_map.c	\
		player_position.c	\
		check_win.c	\
		check_lose.c	\
		check_map.c	\
		input_player_two.c	\
		player_two.c	\
		check_tp.c	\

CFLAGS	=	-Wall -Wextra -I./include/ -L./lib/my/ -lmy -lncurses

SRC_LIB	=	lib/my/my_strcmp.c	\
			lib/my/mini_printf.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

OBJ	=	$(SRC_LIB:.c=.o)

SRC_TESTS = tests/Test_Valid_Map.c	\
			tests/Test_Generate_Map.c	\
			tests/Test_Replace_Map.c	\
			tests/Test_print_help.c	\
			is_valid_map.c 	\
			print_help.c	\
			generate_map.c	\
			replace_map.c	\
			input_player.c	\
			input_player_two.c	\
			print_map.c	\
			player_position.c	\
			check_win.c	\
			check_lose.c	\
			check_map.c	\
			check_tp.c	\

FLAGS_TEST	=	-I./include/ -L./lib/my/ -lmy -lncurses -lcriterion --coverage

all: libmy.a
	gcc -o first_player $(SRC) server.c $(CFLAGS)
	gcc -o my_sokoban $(SRC) one_player.c $(CFLAGS)
	gcc -o second_player $(SRC) client.c $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests

fclean: clean
	rm -f lib/my/libmy.a
	rm -f $(NAME)

re: fclean all

unit_tests: re
	gcc -o unit_tests $(SRC_TESTS) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests
