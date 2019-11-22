##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile that compiles cat
##

NAME	=	bsq

SRC	=	main.c\
		load_map_from_file.c\
		mem_alloc_arrays.c\
		map.c\
		map_initializing.c\
		find_biggest_square.c\
		display_result.c

OBJ	=	$(SRC:.c=.o)

NAME_TESTS = 	tests_bsq

SRC_TESTS =	load_map_from_file.c\
			mem_alloc_arrays.c\
			map_initializing.c\
			map.c\
			find_biggest_square.c\
			display_result.c\
			tests/test_load_map_from_file.c\
			tests/test_get_number_from_line.c\
			tests/test_get_columns_nb_from_file.c\
			tests/test_set_map_dimensions.c\
			tests/test_copy_line_in_arr.c\


OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TESTS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		rm -f *.gcno
		rm -f *.gcda

re:	fclean all

tests_run: 	$(OBJ_TESTS)
			gcc -o $(NAME_TESTS) $(OBJ_TESTS) --coverage -lcriterion
			./$(NAME_TESTS)