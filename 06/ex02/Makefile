NAME = Identify
SRCS = main.cpp  utils.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
CXX = c++



all: $(NAME)

$(NAME): $(OBJS)
	c++ $(OBJS) $(CXXFLAGS) -o $(NAME)

%.o: %.cpp
	c++ -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


