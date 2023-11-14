##
## EPITECH PROJECT, 2023
## n4s [WSL : Ubuntu]
## File description:
## Makefile
##

MAIN = main.c \

SRC	=	src/my_str_to_word_array.c 		\
		src/my_strcmp.c				\
		src/my_free.c 			\
		src/ns/detect_wall.c 				\
		src/ns/check_wall.c 				\
		src/ns/speed.c				\
		src/ns/turn_ia.c		\
		src/ns/simulation_ia.c			\

NAME    =	ai

all:    $(NAME)

$(NAME):	$(SRC)
	@echo -e "\e[0m\e[1mConstruction de la librairie..."
	@echo -e "\e[1m\e[32mConstruction terminée avec succès !"
	@echo -e "\e[0m\e[1mConstruction de l'executable..."
	@gcc -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) $(LIB) -g
	@echo -e "\e[1m\e[32mConstruction terminée avec succès !"

clean:
	@echo -e "\e[0m\e[1mNettoyage des fichiers..."

fclean: clean
	@rm -f $(NAME)
	@rm -f *.gnco
	@rm -f ../../include/$(NAME)

tests_run:
	gcc -o unit_tests $(SRC) $(TESTS) -lcriterion --coverage
	./unit_tests

re:		fclean all

mr_clean :
	find -type f -name "*~" -delete -o -type f -name "#*#" -delete

.PHONY : all clean fclean mr_clean re
