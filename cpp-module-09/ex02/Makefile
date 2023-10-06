SRCS = main.cpp PmergeMe.cpp

CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98

NAME = PmergeMe

CXX = c++

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all