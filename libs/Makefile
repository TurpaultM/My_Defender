##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Library Makefile
##

SRC		=	my/my_arrlen.c						\
			my/int_to_char.c					\
			my/my_revstr.c						\
			my/my_strcat.c						\
			my/my_strcmp.c						\
			my/my_strstr.c						\
			my/my_strncmp.c						\
			my/my_strcpy.c						\
			my/my_strdup.c						\
			my/concat_n_string.c				\
			my/my_strlen.c						\
			my/my_len.c							\
			my/my_strwordarray.c				\
			my/my_strtok.c						\
			my/nbtochar.c						\
			myprintf/my_compute_power_rec.c		\
			myprintf/my_getnbr.c				\
			myprintf/my_put_nbr_hexadecimal.c	\
			myprintf/my_put_nbr_octal.c			\
			myprintf/my_put_nbrf.c				\
			myprintf/my_put_nbr.c				\
			myprintf/my_putstr.c				\
			myprintf/my_putsterr.c				\
			myprintf/my_putchar.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CC		=	gcc

all:	$(NAME)

inc:
	cp ../includes/my.h ../libs
	cp ../includes/printf.h ../libs

$(NAME):	inc $(OBJ)
		ar rc -o $(NAME) $(OBJ)
		$(RM) *.h

clean:
		$(RM) $(OBJ)
		$(RM) *.gc*
		$(RM) *.o

fclean: 		clean
		$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY= clean all re fclean
