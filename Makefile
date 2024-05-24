NAME =one

CC= cc

SRC = main.c

INCLUDE = -I structs.h

CFLAGS = -Wall -Wextra -Werror

OBJ =$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $(NAME)

%.o: %.c Makefile structs.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re