NAME = harl
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp harl.cpp
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
