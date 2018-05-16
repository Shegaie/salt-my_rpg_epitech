##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rémi BISSON
##
SRC	=	my_strdup.c		\
		get_next_line.c		\
		my_strcat.c		\
		is_in_str.c		\
		my_strlen.c		\
		itoa.c

OBJ	=	$(SRC:.c=.o)
INC	=	lib.h
GNL	=	get_next_line.h
NAME	=	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	cp $(INC) ../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
