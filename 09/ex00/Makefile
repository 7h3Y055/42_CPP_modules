NAME = btc
SRCS = BitcoinExchange.cpp check_input_file.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -std=c++98 -fsanitize=address #-Wall -Werror -Wextra
CXX = c++


$(NAME): all

all: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo -e "\n\n\n";
	@echo -e "=========================================";
	@./$(NAME) input.txt | cat -e
	@echo -e "=========================================";

.o: .cpp
	$(CXX) $(CXXFLAGS) -c $> -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all