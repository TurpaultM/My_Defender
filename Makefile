##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## to complete
##

SRC			=	sources/Menu/menu.c
SRC			+=	sources/Menu/button_gest.c
SRC			+=	sources/game/menu_game.c
SRC			+=	sources/game/init_menu_game.c
SRC			+=	sources/game/jiggly_anim.c
SRC			+=	sources/game/jiggly_collide.c
SRC			+=	sources/game/jiggly_move.c
SRC			+=	sources/game/pause.c
SRC			+=	sources/game/how_to_play/how.c
SRC			+=	sources/game/initialisation.c
SRC			+=	sources/game/check_end_condition.c
SRC			+=	sources/game/functions_in_game/animations.c
SRC			+=	sources/game/functions_in_game/attacks.c
SRC			+=	sources/game/functions_in_game/calculate_rotations.c
SRC			+=	sources/game/functions_in_game/create_defenders_textures.c
SRC			+=	sources/game/functions_in_game/create_defenders.c
SRC			+=	sources/game/functions_in_game/create_patterns.c
SRC			+=	sources/game/functions_in_game/create_pokemons_structure.c
SRC			+=	sources/game/functions_in_game/create_pokemons.c
SRC			+=	sources/game/functions_in_game/destroy.c
SRC			+=	sources/game/functions_in_game/detect_enemies.c
SRC			+=	sources/game/functions_in_game/display_total_life_and_evolve.c
SRC			+=	sources/game/functions_in_game/display.c
SRC			+=	sources/game/functions_in_game/end_of_the_game.c
SRC			+=	sources/game/functions_in_game/evolutions.c
SRC			+=	sources/game/functions_in_game/game.c
SRC			+=	sources/game/functions_in_game/initialize_pokemons.c
SRC			+=	sources/game/functions_in_game/movements_functions.c
SRC			+=	sources/game/functions_in_game/movements.c
SRC			+=	sources/game/functions_in_game/numel_attack.c
SRC			+=	sources/game/functions_in_game/place_defenders_in_squares.c
SRC			+=	sources/game/functions_in_game/place_defenders.c
SRC			+=	sources/game/functions_in_game/shiny.c
SRC			+=	sources/game/functions_in_game/struct_copy_textures.c
SRC			+=	sources/game/functions_in_game/struct_copy.c
SRC			+=	sources/bestiary/bestiary.c
SRC			+=	sources/bestiary/init_bestiary.c
SRC			+=	sources/bestiary/utilitary_bestiary.c
SRC			+=	sources/option/option.c
SRC			+=	sources/option/music.c
SRC			+=	sources/option/init_opt.c

MAIN		=	sources/main/main.c

SRCT		=	tests/tests_my_defender.c		\
				tests/tests_functions_in_game.c

OBJ			=	$(SRC:%.c=%.o)

OBJM		=	$(MAIN:%.c=%.o)

OBJT		=	$(SRCT:%.c=%.o)

CC			=	gcc

MAKE		=	make

NAME		=	my_defender

NAMET		=	unit_tests

INCLUDES	=	-I./includes

CFLAGS		=	-Wall -Wextra -Wunknown-pragmas
CFLAGS		+=	$(INCLUDES)
LDFLAGS		=	-lmy -L./libs -lcsfml-graphics
LDFLAGS		+=	-lcsfml-window -lcsfml-audio -lcsfml-system -lm

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJM)
	$(MAKE) -C libs/
	$(CC) -o $(NAME) $(OBJ) $(OBJM) $(LDFLAGS)

tests_run:	CFLAGS	+=	-lcriterion
tests_run:	LDFLAGS +=	--coverage
tests_run:
	$(MAKE) -C libs/
	$(CC) -o $(NAMET) $(SRCT) $(SRC) $(LDFLAGS)

unit_test: tests_run
	./unit_test

coverage:	unit_test
	gcovr

clean:
	$(RM) *~
	$(RM) *#
	$(RM) *.gc*
	$(RM) sources/*.o
	$(RM) sources/main/*.o
	$(RM) sources/game/*.o
	$(RM) sources/game/functions_in_game/*.o
	$(RM) sources/game/how_to_play/*.o
	$(RM) sources/bestiary/*.o
	$(RM) sources/option/*.o
	$(RM) sources/Menu/*.o
	$(MAKE) -C libs/ clean

fclean:		clean
	$(RM) $(NAME)
	$(RM) unit_test
	$(MAKE) -C libs/ fclean

debug: CFLAGS += -g
debug: re

re:		fclean all

.PHONY= clean fclean re all tests_run coverage
