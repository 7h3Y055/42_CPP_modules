NAME = bank
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
