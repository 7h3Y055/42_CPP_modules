NAME = PmergeMe
SRCS = ft_deque.cpp  ft_list.cpp  main.cpp  PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -g3 -g -fsanitize=address #-Wall -Werror -Wextra
CXX = c++



all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	c++ -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: clean fclean re
.SECONDARY: $(OBJS)

