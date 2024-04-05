NAME=megaphone
SRC=megaphone.cpp
CFLAGS=-Wall -Werror -Wextra -std=c++98
CC=c++

$(NAME):$(SRC)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

all:$(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
