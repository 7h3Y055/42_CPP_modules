NAME = RPN
SRCS = RPN.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -g -g3 -fsanitize=address #-Wall -Werror -Wextra
CXX = c++



all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
# @echo -e "\n\n\n";
# @echo -e "=========================================";
# @./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +" | cat -e
# @echo -e "=========================================";

%.o: %.cpp
	c++ -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all





.PHONY: clean fclean re
.SECONDARY: $(OBJS)