NAME = btc
SRCS = BitcoinExchange.cpp check_input_file.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
CXX = c++


$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $> -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all