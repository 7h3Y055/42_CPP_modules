NAME = brain
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fsanitize=address
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re
.SECONDARY: $(OBJS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
