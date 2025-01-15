##
## EPITECH PROJECT, 2024
## Makeffile
## File description:
## Makefile
##

CC = gcc
SRC = cipher.c matrix.c print.c print2.c deencrypt.c calc.c inverse.c calc2.c

OBJ = $(SRC:.c=.o)
NAME = 103cipher

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.log
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all
